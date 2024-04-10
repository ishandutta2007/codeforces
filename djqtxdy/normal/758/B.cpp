/*
	xx



  







 

*/
/*



 . 











	 
 
...

.

 
{
^ma
|zzzz|



z|||z


	


M





}{

 
 


 M M M
/M
    
   
Wiiiiiiii M 
dpppppppp


q-rq-rq---rq-rq-rq---rqr
q--sq-r
t-st-r
q-rq-st--rt--r
t--rt-sts
t-st-st---st----st----st---s 

jTTjXTrTmTrTjTUTTpTrXXmrX
dTTgUUtTaUUUUUUtTUUtT
dTTgUUtTaaUUUUUUUXdTgX
mTTptTaXTrUUdstpTTpTmtTtTatT
TTTjTTsUUUUUUXarTTTpTTT
TTpTTUUUmmTUUUUU U
TTTmTTTtTapTTTUtatataU ^s

------
--
--------
--


qTTTTTTr
U   U
Ute
U  
Uqe 
U / U
tTTTTTTs 
~*~*~
*~*~

v

v
v

vv?
vv
v
vv
v
v
v
v
v

??
???
???
__ __?
nnn?

nnnn?




..o+?''o?''oso+?''o?''o
X--[XT-YX-[q-TrXT-[V[
V-_V[^-_WTsXYX-a
^-[\`X-[^-[
X-_qT_
\_\_^-_\tTs\_\`^-T_
o+?''o?''oso+?''o?''o

XTT[X[X[X[
^[XaUUXTjjjT[U^adTjj[
Xa^[U^gUUUUdg^[XgUUUU
^TTa^TmTmTmTa^a^TmTa

	


 



M     M M
<  >    
     MM 

 qrqr

q-------r



ts
t-s
t-------s
 qrqr
 t----s

..


..
..

""


ts




















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
map<char,bool> vis;
map<char,int> ans;
int main(){
	string s;
	cin>>s;
	for (int i=0;i<s.length();i++){
		if (s[i]=='!') continue;
		if (!vis.count(s[i])){
			vis[s[i]]=true;
			for (int j=i%4;j<s.length();j+=4){
				if (s[j]=='!') ans[s[i]]++;
			}
		}
	}
	printf("%d %d %d %d\n",ans['R'],ans['B'],ans['Y'],ans['G']);
	return 0;
}