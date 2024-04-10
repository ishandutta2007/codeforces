/*
	



  







 

*/
/*



 . 











	 
 
...

.

 









	










 
 


   
/
    
   
  



----------
---
--
------
---
---------------- 






 
 

------
--
--------
--



   

  
 
 / 
 
~*~*~
*~*~






?









??
???
???
__ __?
?

?




..o+?''o?''oo+?''o?''o
------
---
---
-
--
o+?''o?''oo+?''o?''o






	


 



      
<  >    
      

 

-------




-
-------
 
 ----

..


..
..

""























*/

/*
			  ********
               ************
               ####....#.
             #..###.....##....
             ###.......######              ###                 ###           ###           ###
                ...........               #...#               #...#         #...#         #...#
               ##*#######                 #.#.#               #.#.#         #.#.#         #.#.#
            ####*******######             #.#.#               #.#.#         #.#.#         #.#.#
           ...#***.****.*###....          #...#               #...#         #...#         #...#
           ....**********##.....           ###                 ###           ###           ###
           ....****    *****....
             ####        ####
           ######        ######
##############################################################              ##################################
#...#......#.##...#......#.##...#......#.##------------------#              #...#......#.##------------------#
###########################################------------------#              ###############------------------#
#..#....#....##..#....#....##..#....#....#####################              #..#....#....#####################
##########################################    #----------#                  ##############    #----------#
#.....#......##.....#......##.....#......#    #----------#                  #.....#......#    #----------#
##########################################    #----------#                  ##############    #----------#
#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#                  #.#..#....#..#    #----------#
##########################################    ############                  ##############    ############
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
//orz mqy
const int Maxl=65;
int dp[Maxl][Maxl];
int ans[Maxl];
vector<string> cnt;
int n;
long long ret=1e18;
const long long INFi=3e18; 
string k;
long long s_i(string x){
	long long val=0;
	for (int i=0;i<x.length();i++){
		val=val*10+(long long)(x[i]-'0');
	}
	return val;
}
bool over(string x){
	if (x[0]=='0' && (int)x.length()!=1) return true;
	if ((int)x.length()>10) return true;
	long long val=0;
	for (int i=0;i<x.length();i++){
		val=val*10+(long long)(x[i]-'0');
	}
	return val>=(long long)n;
}
void solve(){
	for (int i=0;i<k.length();i++){
		string str=k.substr(i);
		for (int j=0;j<Maxl;j++){
			dp[i][j]=INF;
		}
		for (int j=0;j<str.length();j++){
			for (int k=0;k<=j;k++){
				if (!over(str.substr(k,j-k+1))){
					if (k==0) dp[i][j]=min(dp[i][j],1);
					else{
						dp[i][j]=min(dp[i][j],dp[i][k-1]+1);
					}
				}
			}
		}
		ans[i]=dp[i][str.length()-1];
		//printf("%d ",ans[i]);
	}
}
long long calc(){
	long long tot=0;
	for (int i=0;i<cnt.size();i++){
		if (INFi/(LL)n<tot) return INFi;
		tot=tot*(LL)n+s_i(cnt[i]); 
	}
	return tot;
}
void Search(int lvl){
//	cout<<lvl<<endl;
	if (lvl==(int)k.length()){
		if ((int)cnt.size()>ans[0]) return;
		ret=min(ret,calc());
		return;
	}
	string bck=cnt.back();
	if (!over(bck+k[lvl])){
		cnt[cnt.size()-1]+=k[lvl];
		Search(lvl+1);
		cnt[cnt.size()-1]=bck;
	}
	if ((int)cnt.size()+ans[lvl]<=ans[0]){
		cnt.push_back("");
		cnt[cnt.size()-1]+=k[lvl];
		Search(lvl+1);
		cnt.pop_back();
	}
}
int main(){
	scanf("%d",&n);
	cin>>k;
	solve();
	cnt.push_back("");
	Search(0);
	printf("%I64d\n",ret);
	return 0;
}