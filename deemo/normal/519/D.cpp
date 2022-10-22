#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<utility>

using namespace std;

typedef long long ll;
ll ans;
set<pair<ll , ll>>	  st[30];
pair<ll , ll>	  tz;
int val[30];
int last[40];
ll z[30];
string s;
const int max_n = 6 * 1e5 + 300;
ll  p[max_n];
//ll w[35][3 * max_n];
map<ll , ll>   w[30];

bool operator < (pair<ll , ll>  a , pair<ll , ll>   b){
    return  a.second < b.second;
}

int main(){
    for (int i = 0 ; i < 26 ; i++){
	 cin >> val[i];
	 last[i] = -1;
    }
    cin >> s;
    for (int i = 0 ; i < s.size() ; i++){ 
	 if (i == 0) p[i] = val[s[i] - 97];   
	 else	  p[i] = val[s[i] - 97] + p[i - 1];
    }
    //size 70,dore akhar seg fault
    for (int i = 0 ; i < s.size() ; i++){
	 if (last[s[i] - 97] == -1){
	     last[s[i] - 97] = i;
	     continue;
	 }	      

	 int m = last[s[i] - 97];//jaaye chare moshabehe ghabli
	 char c = s[i];
	 ll t = p[i] - p[m] - val[c - 97];//faselehe i om ta char e moshabehe ghabli
	 if (t == 0) ans++;
	 ll temp = t + val[s[m] - 97];  
	 temp = -temp;//meghdari ke bayad az ghabli berim unvar
	 temp -= z[c - 97];
	 if (st[c - 97].find({w[c - 97][temp] , temp}) != st[c - 97].end()){//3 , 
	     tz = *st[c - 97].find({w[c - 97][temp] , temp});
	     ans += tz.first;
	 }
	 z[c - 97] += t + val[s[m] - 97];//t faselehe in char ba moshabehe ghabli
	 t = t - z[c - 97];
	 if (st[c - 97].find({w[c - 97][t] , t}) != st[c - 97].end()){
	     tz = *st[c - 97].find({w[c - 97][t] , t});
	     st[c - 97].erase(tz);
	     tz.first += 1;
	     st[c - 97].insert(tz);
	     w[c - 97][tz.second] += 1;
	 }   
	 else{
	     tz.first = 1;
	     tz.second = t;
	     w[c - 97][tz.second] += 1;//inja kharab mishe
	     st[c - 97].insert(tz);
	 }
	 last[c - 97] = i;
    }
    cout << ans << endl;

    return 0;
}