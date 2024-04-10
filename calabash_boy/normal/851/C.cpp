#pragma warning(disable:4786)//  
#pragma comment(linker, "/STACK:102400000,102400000")// 
#include <vector>  
#include <list>  
#include <map>  
#include <set>  
#include <deque>  
#include <queue>  
#include <stack>  
#include <bitset>   
#include <algorithm>  
#include <functional>  
#include <numeric>  
#include <utility>  
#include <complex>  
#include <sstream>  
#include <iostream>  
#include <iomanip>  
#include <cstdio>  
#include <cmath>  
#include <cstdlib>  
#include <cstring>  
#include <ctime>  
#include <cassert>  
using namespace std;  
#define lson 2*i    
#define rson 2*i+1    
#define LS l,mid,lson    
#define RS mid+1,r,rson    
#define UP(i,x,y) for(i=x;i<=y;i++)    
#define DOWN(i,x,y) for(i=x;i>=y;i--)    
#define MEM(a,x) memset(a,x,sizeof(a))    
#define W(a) while(a)    
#define gcd(a,b) __gcd(a,b)       
#define N 1000005    
#define MOD 1000000007    
#define INF 0x3f3f3f3f    
#define EXP 1e-8    
#define lowbit(x) (x&-x) 
typedef long long LL;
const int NNN=1000000009;  
const LL modd = 1e9 + 7;  
const double PI = acos(-1.0);  
const double E = exp(1);  
const double EPS=1e-8;   
inline int read(){
	char ch=getchar();int rre=0;
	while (ch<'0'||ch>'9')ch = getchar();
	while (ch>='0'&&ch<='9')rre = rre*10+ch-'0',ch = getchar();
	return rre;
} 
inline LL readLL(){
	char chLL = getchar();LL rreLL=0LL;
	while (chLL<'0'||chLL>'9')chLL = getchar();
	while (chLL>='0'&&chLL<='9')rreLL = 10*rreLL+chLL-'0',chLL = getchar();
	return rreLL;
}
const int maxn = 1005;
int n;

struct node{
    int x[7];
};
node arr[maxn];

vector<int> ans;

int check(int ii,int j,int k){
    node A,B;
    for (int i=0;i<=4;i++)A.x[i]=arr[j].x[i]-arr[ii].x[i],B.x[i]=arr[k].x[i]-arr[ii].x[i];
    int t=0;
    for (int i=0;i<=4;i++)t += A.x[i]*B.x[i];
    return t;
}
void input(){
	scanf("%d",&n);
	   for(int i=1;i<=n;i++)for(int t=0;t<5;t++)   scanf("%d",&arr[i].x[t]);
}
int main(){
	input();

    for(int i=1;i<=n;i++){
        bool ok=1;
        for(int j=1;j<n;j++){
            if(j==i) continue;
            for(int k=j+1;k<=n;k++){
                if(k==i) continue;
                if(check(i,j,k)>0){
                    ok=0;
                    break;
                }
            }
        }
        if(ok) ans.push_back(i);
    }
    
    printf("%d\n",(int)ans.size());
    for(auto t:ans) printf("%d\n",t);
    return 0;
}