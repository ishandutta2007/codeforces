#include <iostream>
#define rep(i,a) for(int i=0;i<a;i++)
using namespace std;
int a[1005][1005],b[1005][1005];
int main(){
int T;cin>>T;while(T--){
int n,q;cin>>n>>q;
rep(i,n)rep(j,n){cin>>a[i][j];a[i][j]--;}
pair<int,int> x={0,0},y={1,0},z={2,0};
rep(i,q){char c;cin>>c;
x.second += n+(c=='D')-(c=='U');
y.second += n+(c=='R')-(c=='L');
if(c=='I')swap(y,z);
if(c=='C')swap(x,z);
}
rep(i,n)rep(j,n){
static int R[3];
R[0]=i,R[1]=j,R[2]=a[i][j];
b[(R[x.first]+x.second)%n][(R[y.first]+y.second)%n]=(R[z.first]+z.second)%n;
}
rep(i,n)rep(j,n)cout<<b[i][j]+1<<" \n"[j==n-1];
cout<<endl;
}
}