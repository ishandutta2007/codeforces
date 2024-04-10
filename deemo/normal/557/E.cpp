#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;
string s , pat;
const int max_n = 20000;
int k;
int z[max_n];
vector<int> save[max_n];
vector<int> sec;
int part[6000][6000];

void init(){
    int b , e , add;
    for (int i = 0 ; i < s.size() ; i++){
	 add = 1;    b = i;	e = i;
	 while (b >= 0 && e < s.size() && add < 3){
	     if (s[b] != s[e]){
		  if (add == 1){
		      b -= add;   e += add;	  
		      add += 1;
		      continue;
		  }
		  add += 1;
		  continue;
	     }
	     save[b].push_back(e);
	     b -= add;   e += add;
	 }
    }

    for (int i = 0 ; i < s.size() - 1 ; i++){
	 add = 1;    b = i;	e = i + 1;
	 while (b >= 0 && e < s.size() && add < 3){
	     if (s[b] != s[e]){
		  if (add == 1){
		      b -= add;   e += add;	  
		      add += 1;
		      continue;
		  }
		  add += 1;
		  continue;
	     }
	     save[b].push_back(e);
	     b -= add;   e += add;
	 }
    }
    
    for (int i = 0 ; i < s.size() ; i++)
	 sort(save[i].begin() , save[i].end());

    for (int i = 0 ; i < s.size() ; i++){
	 int p = 1;
	 for (int j = i ; j < s.size() ; j++){
	     if (j == i) part[i][j] = 1;
	     else{
		  part[i][j] = part[i][j - 1];
		  if (save[i][p] == j){
		      p++;
		      part[i][j] += 1;
		  }
	     }	  
	 }
    }
}   

void find_matches(){
    sec.clear();
    string t = pat + '@' + s;
    int L , R;
    L = R = 0;
    for (int i = 1 ; i < t.size() ; i++){
	 if (R < i){
	     L = R = i;
	     while (R < t.size() && t[R] == t[R - i])	R++;
	     R--;
	     z[i] = R - i + 1;
	 }
	 else{
	     if (z[i - L] < R - i + 1)   z[i] = z[i - L];
	     else{
		  L = i;
		  while (R < t.size() && t[R] == t[R - L])    R++;
		  R--;
		  z[i] = R - i + 1;
	     }
	 }
    }
    for (int i = pat.size() + 1 ; i < t.size() ; i++)
	 if (z[i] == pat.size()) sec.push_back(i - (pat.size() + 1));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    cin >> k;
    init();
    int cnt , ret , flag;
    while (k > 0){
	 pat += 'a';
	 cnt = flag = 0;
	 find_matches();
	 for (int i = 0 ; i < sec.size() ; i++){
	     int t = sec[i];
	     if (t + pat.size() - 1 == 0)	  cnt += save[t].size();
	     else    cnt += save[t].size() - part[t][t + pat.size() - 2];
	     
	     if (t + pat.size() - 1 == 0)	  flag++;
	     else    if (part[t][t + pat.size() - 1] > part[t][t + pat.size() - 2])	flag++;
	 }
	 if (cnt < k){
	     pat[pat.size() - 1] = 'b';
	     k -= cnt; 

	     find_matches();
	     flag = 0;
	     for (int i = 0 ; i < sec.size() ; i++){
		  int t = sec[i];
		  if (t + pat.size() - 1 == 0)	  cnt += save[t].size();
		  else    cnt += save[t].size() - part[t][t + pat.size() - 2];
		      
		  if (t + pat.size() - 1 == 0)	  flag++;
		  else    if (part[t][t + pat.size() - 1] > part[t][t + pat.size() - 2])	flag++;
	     }

	     k -= flag;
	 }
	 else	  k -= flag;
    }
    cout << pat << endl;
    return 0;
}