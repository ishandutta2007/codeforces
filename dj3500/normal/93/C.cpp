#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
using namespace std;
#define pb push_back
#define INF 2147483647
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define sz size()
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,t.size())s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end()) 
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));

string ciag[300];
int main () {

ciag[1] = "0\n";
ciag[2] = "1\nlea ebx, [2*eax]";
ciag[3] = "1\nlea ebx, [eax + 2*eax]";
ciag[4] = "1\nlea ebx, [4*eax]";
ciag[5] = "1\nlea ebx, [eax + 4*eax]";
ciag[6] = "2\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]";
ciag[7] = "2\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 2*ebx]";
ciag[8] = "1\nlea ebx, [8*eax]";
ciag[9] = "1\nlea ebx, [eax + 8*eax]";
ciag[10] = "2\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]";
ciag[11] = "2\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*eax]";
ciag[12] = "2\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]";
ciag[13] = "2\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*ebx]";
ciag[14] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 2*ecx]";
ciag[15] = "2\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]";
ciag[16] = "2\nlea ebx, [2*eax]\nlea ecx, [8*ebx]";
ciag[17] = "2\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]";
ciag[18] = "2\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*ebx]";
ciag[19] = "2\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 2*ebx]";
ciag[20] = "2\nlea ebx, [4*eax]\nlea ecx, [ebx + 4*ebx]";
ciag[21] = "2\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 4*ebx]";
ciag[22] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ebx]";
ciag[23] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ecx + 8*eax]";
ciag[24] = "2\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]";
ciag[25] = "2\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*ebx]";
ciag[26] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 4*ecx]";
ciag[27] = "2\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]";
ciag[28] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 2*ecx]";
ciag[29] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ecx + 2*eax]";
ciag[30] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 4*ecx]";
ciag[31] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [eax + 2*ecx]";
ciag[32] = "2\nlea ebx, [4*eax]\nlea ecx, [8*ebx]";
ciag[33] = "2\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]";
ciag[34] = "3\nlea ebx, [2*eax]\nlea ecx, [4*eax]\nlea edx, [ebx + 8*ecx]";
ciag[35] = "3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 2*ecx]";
ciag[36] = "2\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*ebx]";
ciag[37] = "2\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 4*ebx]";
ciag[38] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 2*ecx]";
ciag[39] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ebx + 4*ecx]";
ciag[40] = "2\nlea ebx, [8*eax]\nlea ecx, [ebx + 4*ebx]";
ciag[41] = "2\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 8*ebx]";
ciag[42] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 4*ecx]";
ciag[43] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ebx + 8*ecx]";
ciag[44] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ecx + 8*ebx]";
ciag[45] = "2\nlea ebx, [eax + 4*eax]\nlea ecx, [ebx + 8*ebx]";
ciag[46] = "3\nlea ebx, [eax + 4*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [eax + 1*ecx]";
ciag[47] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 4*ecx]";
ciag[48] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [8*ecx]";
ciag[49] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [eax + 8*ecx]";
ciag[50] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*ecx]";
ciag[51] = "3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]";
ciag[52] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 4*ecx]";
ciag[53] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [eax + 4*ecx]";
ciag[54] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ecx]";
ciag[55] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [eax + 2*ecx]";
ciag[56] = "3\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\nlea edx, [ebx + 2*ecx]";
ciag[57] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 2*ecx]";
ciag[58] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*eax]\nlea eex, [edx + 8*ecx]";
ciag[59] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 2*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[60] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ecx + 4*ecx]";
ciag[61] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [eax + 4*ecx]";
ciag[62] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 2*ecx]\nlea eex, [ecx + 4*edx]";
ciag[63] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 4*ecx]";
ciag[64] = "2\nlea ebx, [8*eax]\nlea ecx, [8*ebx]";
ciag[65] = "2\nlea ebx, [8*eax]\nlea ecx, [eax + 8*ebx]";
ciag[66] = "3\nlea ebx, [2*eax]\nlea ecx, [8*eax]\nlea edx, [ebx + 8*ecx]";
ciag[67] = "3\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 2*ecx]";
ciag[68] = "3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [4*ecx]";
ciag[69] = "3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 4*ecx]";
ciag[70] = "3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ebx + 4*ecx]";
ciag[71] = "4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [eax + 8*ebx]\nlea eex, [ecx + 4*edx]";
ciag[72] = "2\nlea ebx, [8*eax]\nlea ecx, [ebx + 8*ebx]";
ciag[73] = "2\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 8*ebx]";
ciag[74] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 4*ecx]";
ciag[75] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ebx + 8*ecx]";
ciag[76] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 2*ecx]";
ciag[77] = "3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ebx + 8*ecx]";
ciag[78] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*ebx]\nlea eex, [ecx + 4*edx]";
ciag[79] = "4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 4*edx]";
ciag[80] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [8*ecx]";
ciag[81] = "2\nlea ebx, [eax + 8*eax]\nlea ecx, [ebx + 8*ebx]";
ciag[82] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 8*ecx]";
ciag[83] = "3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 2*ecx]";
ciag[84] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 4*ecx]";
ciag[85] = "3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 4*ecx]";
ciag[86] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*eax]\nlea eex, [ecx + 8*edx]";
ciag[87] = "3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ebx + 2*ecx]";
ciag[88] = "3\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\nlea edx, [ecx + 8*ebx]";
ciag[89] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [eax + 8*ecx]";
ciag[90] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ecx + 8*ecx]";
ciag[91] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 8*ecx]";
ciag[92] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 1*ecx]\nlea eex, [edx + 8*ecx]";
ciag[93] = "3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 2*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[94] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 4*edx]";
ciag[95] = "3\nlea ebx, [eax + 4*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 2*ecx]";
ciag[96] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [8*ecx]";
ciag[97] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [eax + 8*ecx]";
ciag[98] = "4\nlea ebx, [2*eax]\nlea ecx, [4*eax]\nlea edx, [ecx + 8*eax]\nlea eex, [ebx + 8*edx]";
ciag[99] = "3\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]";
ciag[100] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 8*ecx]";
ciag[101] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 4*ecx]";
ciag[102] = "4\nlea ebx, [2*eax]\nlea ecx, [4*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [edx + 2*edx]";
ciag[103] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ebx + 4*ecx]";
ciag[104] = "3\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\nlea edx, [ebx + 4*ecx]";
ciag[105] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [eax + 8*ecx]";
ciag[106] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ebx + 4*edx]";
ciag[107] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[108] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ecx + 8*ecx]";
ciag[109] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [eax + 4*ecx]";
ciag[110] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ecx + 4*edx]";
ciag[111] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 4*ecx]";
ciag[112] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 2*ecx]\nlea eex, [8*edx]";
ciag[113] = "3\nlea ebx, [eax + 8*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*ecx]";
ciag[114] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 2*ecx]\nlea eex, [ebx + 8*edx]";
ciag[115] = "4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ecx + 8*edx]";
ciag[116] = "4\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 4*ebx]\nlea eex, [edx + 8*ecx]";
ciag[117] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ecx + 8*ecx]";
ciag[118] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 2*ecx]\nlea eex, [ecx + 8*edx]";
ciag[119] = "4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\nlea eex, [ecx + 2*edx]";
ciag[120] = "3\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\nlea edx, [ecx + 4*ecx]";
ciag[121] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [eax + 8*ecx]";
ciag[122] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 4*ecx]\nlea eex, [ebx + 4*edx]";
ciag[123] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[124] = "4\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 2*ecx]\nlea eex, [ecx + 4*edx]";
ciag[125] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 4*ecx]";
ciag[126] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 2*ecx]\nlea eex, [edx + 8*edx]";
ciag[127] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 4*ecx]\nlea eex, [eax + 2*edx]";
ciag[128] = "3\nlea ebx, [2*eax]\nlea ecx, [8*ebx]\nlea edx, [8*ecx]";
ciag[129] = "3\nlea ebx, [2*eax]\nlea ecx, [8*ebx]\nlea edx, [eax + 8*ecx]";
ciag[130] = "3\nlea ebx, [2*eax]\nlea ecx, [8*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[131] = "3\nlea ebx, [8*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 2*ecx]";
ciag[132] = "3\nlea ebx, [4*eax]\nlea ecx, [4*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[133] = "3\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 4*ecx]";
ciag[134] = "4\nlea ebx, [2*eax]\nlea ecx, [4*eax]\nlea edx, [eax + 8*ecx]\nlea eex, [ebx + 4*edx]";
ciag[135] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ecx + 8*ecx]";
ciag[136] = "3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [8*ecx]";
ciag[137] = "3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 8*ecx]";
ciag[138] = "3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[139] = "4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [eax + 8*ebx]\nlea eex, [ecx + 8*edx]";
ciag[140] = "3\nlea ebx, [4*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[141] = "4\nlea ebx, [2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [eax + 8*ebx]\nlea eex, [ecx + 8*edx]";
ciag[142] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [eax + 8*ebx]\nlea eex, [ecx + 8*edx]";
ciag[143] = "4\nlea ebx, [4*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 4*edx]";
ciag[144] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [8*ecx]";
ciag[145] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [eax + 8*ecx]";
ciag[146] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[147] = "3\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 2*ecx]";
ciag[148] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 4*ecx]";
ciag[149] = "3\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [eax + 4*ecx]";
ciag[150] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*ebx]\nlea eex, [ecx + 8*edx]";
ciag[151] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [eax + 2*edx]";
ciag[152] = "3\nlea ebx, [8*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 2*ecx]";
ciag[153] = "3\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 8*ecx]";
ciag[154] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 8*ebx]\nlea eex, [ecx + 8*edx]";
ciag[155] = "3\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ebx + 2*ecx]";
ciag[156] = "4\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 8*ebx]\nlea eex, [ecx + 4*edx]";
ciag[157] = "3\nlea ebx, [eax + 8*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ebx + 4*ecx]";
ciag[158] = "4\nlea ebx, [4*eax]\nlea ecx, [ebx + 2*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 4*edx]";
ciag[159] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ebx + 4*edx]";
ciag[160] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [8*ecx]";
ciag[161] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [eax + 8*ecx]";
ciag[162] = "3\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ecx + 8*ecx]";
ciag[163] = "3\nlea ebx, [eax + 8*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [eax + 2*ecx]";
ciag[164] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[165] = "3\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 4*ecx]";
ciag[166] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [ebx + 2*edx]";
ciag[167] = "4\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 4*ecx]\nlea eex, [edx + 2*eax]";
ciag[168] = "3\nlea ebx, [8*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 4*ecx]";
ciag[169] = "3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [eax + 8*ecx]";
ciag[170] = "4\nlea ebx, [2*eax]\nlea ecx, [4*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [edx + 4*edx]";
ciag[171] = "3\nlea ebx, [eax + 8*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 2*ecx]";
ciag[172] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [eax + 8*ecx]\nlea eex, [ecx + 2*edx]";
ciag[173] = "3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[174] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [ecx + 2*edx]";
ciag[175] = "4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 2*ecx]\nlea eex, [edx + 4*edx]";
ciag[176] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [8*edx]";
ciag[177] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [eax + 8*edx]";
ciag[178] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ebx + 8*edx]";
ciag[179] = "4\nlea ebx, [8*eax]\nlea ecx, [eax + 2*ebx]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 2*edx]";
ciag[180] = "3\nlea ebx, [4*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ecx + 8*ecx]";
ciag[181] = "3\nlea ebx, [eax + 4*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [eax + 4*ecx]";
ciag[182] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 8*edx]";
ciag[183] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*eax]\nlea edx, [ecx + 4*ecx]\nlea eex, [ebx + 4*edx]";
ciag[184] = "4\nlea ebx, [4*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 1*ecx]\nlea eex, [edx + 8*ecx]";
ciag[185] = "3\nlea ebx, [eax + 4*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 4*ecx]";
ciag[186] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 2*ecx]\nlea eex, [ecx + 8*edx]";
ciag[187] = "4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\nlea eex, [edx + 8*ecx]";
ciag[188] = "4\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 4*edx]";
ciag[189] = "3\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ecx + 8*ecx]";
ciag[190] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ecx + 8*ecx]\nlea eex, [ecx + 2*edx]";
ciag[191] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ebx + 4*edx]";
ciag[192] = "3\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\nlea edx, [8*ecx]";
ciag[193] = "3\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\nlea edx, [eax + 8*ecx]";
ciag[194] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [4*ecx]\nlea eex, [ebx + 8*edx]";
ciag[195] = "3\nlea ebx, [8*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]";
ciag[196] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [eax + 8*ecx]\nlea eex, [4*edx]";
ciag[197] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [eax + 8*ecx]\nlea eex, [eax + 4*edx]";
ciag[198] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [edx + 8*edx]";
ciag[199] = "4\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\nlea eex, [eax + 2*edx]";
ciag[200] = "3\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[201] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 8*ecx]";
ciag[202] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [ebx + 4*edx]";
ciag[203] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[204] = "4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\nlea eex, [4*edx]";
ciag[205] = "3\nlea ebx, [eax + 4*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[206] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [ecx + 4*edx]";
ciag[207] = "4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [eax + 4*ecx]\nlea eex, [edx + 2*edx]";
ciag[208] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [8*edx]";
ciag[209] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [eax + 8*edx]";
ciag[210] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ebx + 8*edx]";
ciag[211] = "4\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [ecx + 8*edx]";
ciag[212] = "4\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ebx + 4*edx]";
ciag[213] = "4\nlea ebx, [4*eax]\nlea ecx, [eax + 4*ebx]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 4*edx]";
ciag[214] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ecx + 8*edx]";
ciag[215] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [eax + 8*ebx]\nlea eex, [ecx + 8*edx]";
ciag[216] = "3\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\nlea edx, [ecx + 8*ecx]";
ciag[217] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [eax + 8*ecx]";
ciag[218] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ecx]\nlea eex, [ebx + 4*edx]";
ciag[219] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 8*ecx]";
ciag[220] = "4\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ecx + 4*edx]";
ciag[221] = "4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\nlea eex, [ecx + 4*edx]";
ciag[222] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 8*ecx]\nlea eex, [ecx + 4*edx]";
ciag[223] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ebx + 4*ecx]\nlea eex, [eax + 2*edx]";
ciag[224] = "4\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 2*ecx]\nlea eex, [8*edx]";
ciag[225] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 8*ecx]";
ciag[226] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ecx + 8*eax]\nlea eex, [ecx + 8*edx]";
ciag[227] = "4\nlea ebx, [4*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [ecx + 8*edx]";
ciag[228] = "4\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 2*ecx]\nlea eex, [ebx + 8*edx]";
ciag[229] = "4\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 4*ebx]\nlea eex, [ecx + 4*edx]";
ciag[230] = "4\nlea ebx, [4*eax]\nlea ecx, [ebx + 2*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [ecx + 8*edx]";
ciag[231] = "4\nlea ebx, [4*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\nlea eex, [ecx + 2*edx]";
ciag[232] = "4\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\nlea edx, [ebx + 4*ebx]\nlea eex, [edx + 8*ecx]";
ciag[233] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ecx + 2*eax]\nlea eex, [eax + 8*edx]";
ciag[234] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 4*ecx]\nlea eex, [edx + 8*edx]";
ciag[235] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ecx + 2*eax]\nlea eex, [ebx + 8*edx]";
ciag[236] = "4\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 2*ecx]\nlea eex, [ecx + 8*edx]";
ciag[237] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 4*eax]\nlea edx, [ecx + 8*ebx]\nlea eex, [ecx + 8*edx]";
ciag[238] = "4\nlea ebx, [eax + 4*eax]\nlea ecx, [eax + 1*ebx]\nlea edx, [ebx + 4*ecx]\nlea eex, [ecx + 8*edx]";
ciag[239] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [eax + 2*ebx]\nlea edx, [ebx + 8*ecx]\nlea eex, [ebx + 4*edx]";
ciag[240] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 4*ecx]\nlea eex, [8*edx]";
ciag[241] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 4*ecx]\nlea eex, [eax + 8*edx]";
ciag[242] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 4*ecx]\nlea eex, [ebx + 8*edx]";
ciag[243] = "3\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 8*ebx]\nlea edx, [ecx + 8*ecx]";
ciag[244] = "4\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ecx + 4*ecx]\nlea eex, [ebx + 4*edx]";
ciag[245] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [eax + 8*ecx]\nlea eex, [edx + 4*edx]";
ciag[246] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ecx + 4*ecx]\nlea eex, [ecx + 8*edx]";
ciag[247] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 8*ecx]\nlea eex, [eax + 2*edx]";
ciag[248] = "4\nlea ebx, [8*eax]\nlea ecx, [ebx + 2*ebx]\nlea edx, [ebx + 2*ecx]\nlea eex, [ecx + 4*edx]";
ciag[249] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 8*ecx]\nlea eex, [ebx + 2*edx]";
ciag[250] = "4\nlea ebx, [2*eax]\nlea ecx, [ebx + 4*eax]\nlea edx, [ebx + 8*ecx]\nlea eex, [edx + 4*edx]";
ciag[251] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [eax + 2*ecx]\nlea eex, [ebx + 8*edx]";
ciag[252] = "4\nlea ebx, [4*eax]\nlea ecx, [ebx + 8*eax]\nlea edx, [ebx + 2*ecx]\nlea eex, [edx + 8*edx]";
ciag[253] = "4\nlea ebx, [eax + 2*eax]\nlea ecx, [ebx + 4*ebx]\nlea edx, [ebx + 4*ecx]\nlea eex, [eax + 4*edx]";
ciag[254] = "5\nlea ebx, [2*eax]\nlea ecx, [eax + 2*eax]\nlea edx, [eax + 2*ecx]\nlea eex, [edx + 8*edx]\nlea efx, [ebx + 4*eex]";
ciag[255] = "4\nlea ebx, [2*eax]\nlea ecx, [eax + 8*ebx]\nlea edx, [ecx + 2*ecx]\nlea eex, [edx + 4*edx]";

   wez(n)
   printf("%s",ciag[n].c_str());
}