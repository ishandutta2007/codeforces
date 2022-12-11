#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,a[N],c[N],m,num[N];LL k;
int main(){
    scanf("%d",&n);cin>>k;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),c[i]=a[i];
    sort(c+1,c+n+1);m=unique(c+1,c+n+1)-c-1;
    for(int i=1;i<=n;i++)num[lower_bound(c+1,c+m+1,a[i])-c]++;
    for(int l=1,r=m;;){
        int mn=min(num[l],num[r]),op=num[l]<num[r]?0:1;
        if(l==r||mn>k)printf("%d\n",c[r]-c[l]),exit(0);
        if(op){
            if(k>=1ll*mn*(c[r]-c[r-1]))k-=1ll*mn*(c[r]-c[r-1]),num[r-1]+=num[r],r--;
            else printf("%d\n",c[r]-c[l]-k/mn),exit(0);
        }
        else{
            if(k>=1ll*mn*(c[l+1]-c[l]))k-=1ll*mn*(c[l+1]-c[l]),num[l+1]+=num[l],l++;
            else printf("%d\n",c[r]-c[l]-k/mn),exit(0);
        }
    }
    return 0;
}