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

int n , temp;
const int max_n = 4 * 1e5 + 20;
short jad[max_n];
int a[max_n] , b[max_n] , aa[max_n] , bb[max_n];
int ta , tb , t;
vector<pair<int , int>> ans;

bool help(pair<int , int> a , pair<int , int>   b){
    if (a.first < b.first)	return true;
    if (a.first == b.first && a.second < b.second)  return true;
    return false;
}

int main(){
    cin >> n;
    a[0] = b[0] = 0;
    for (int i = 1 ; i <= n ; i++){
	 scanf("%d" , &temp);
	 jad[i] = temp;//jadvale asli
	 if (temp == 1){
	     ta++;
	     a[ta] = i;//koja avvalin baar ta 1 didim
	 }
	 else{
	     tb++;
	     b[tb] = i;//koja avvalin baar tb 2 didim
	 }
	 aa[i] = ta;//ta khunehe i om chand ta 1
	 bb[i] = tb;//ta khunehe i om chand ta 2
    }
    ta = tb = 0;
    int winner;
    for (int i = 1 ; i <= n ; i++){//toole avvalin set
	 int fl = 0;
	 if (aa[i] == bb[i])    continue;
	 int tta = aa[i] , ttb = bb[i] , sa , sb;//tedaade 1 ha va 2 ha ta inja m tedaade
	 if (jad[i] == 1){//ini ke behesh residim barandeh baashe
	     if (tta <= ttb)	continue;
	     t = tta;
	 }
	 else{// ini ke behesh residim barandeh baashe
	     if (ttb <= tta)	continue;
	     t = ttb;
	 }
	 int s;//tedaad set ha
	 temp = i;//khuneh E ke alan tushuim
	 //borde 1 ha va 2 ha ta inja
	 sa = sb = 0;
	 if (t == tta)   sa = 1;
	 else	  sb = 1;
	 winner = max(sa , sb);
	 for ( ; ;){
	     int ftemp = temp;
	     if (temp == n){//jaE ke akhare sete ghabl budim akharin khunehe jadval bashe
		  fl = 1;
		  break;
	     }
	     temp = min(a[tta + t] , b[ttb + t]);
	     if (temp == 0)	temp = max(a[tta + t] , b[ttb + t]);
	     //age jofteshun be emtiaze morede niaz miresan,uni ke zudtare,vagarna uni ke reside
	     if (temp == 0)	break;//age hichkodum be un emtiaz naresidan
	     if (temp == a[tta + t]){
		  sa++;//age set ro avvalie bordeh
		  winner = sa;
	     }
	     else{
		  sb++;
		  winner = sb;
	     }	  
	     tta = aa[temp];
	     ttb = bb[temp];
	     //inke akharin set ro barandeh bordeh ro nemichekim
	 }
	 s = max(sa , sb);
	 if (s != winner)	continue;
	 if (fl == 0 || sa == sb)	   continue;
	 ans.push_back({s , t});
    }
    sort(ans.begin() , ans.end() , help);
    cout << ans.size() << endl;
    for (int i = 0 ; i < ans.size() ; i++){
	 int p = ans[i].first , o = ans[i].second;
	 printf("%d %d\n" , p , o);
    }
    return 0;
}