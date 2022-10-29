#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=35000007;
const int N=800005;
int t[maxn],a[N],n,pre[maxn];
long long ans,T[35];

int main()
{
    scanf("%d",&n); 
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]); 
        t[a[i]]++;
    }
    for(int bit=24;bit>=0;bit--)
    {
        int mask=(1<<bit),tmp=0; T[bit]=0;
        pre[0]=t[0];
        if(bit==24) 
        {
            for(int i=1;i<mask+mask;i++) pre[i]=0;
            for(int i=1;i<mask+mask;i++) pre[i]=t[i]+pre[i-1];
        }
        else 
        {
            for(int i=1;i<mask*4;i++) pre[i]=0;
            for(int i=1;i<mask*4;i++) pre[i]=t[i]+pre[i-1];
        }
        //if(bit<=3) for(int i=0;i<=10;i++) cout<<pre[i]<<" "; cout<<endl;
        for(int i=1;i<=n;i++)
        {
            if(bit!=24)
            {
                int tt;
                if(mask-a[i]-1<0) tt=0;
                else tt=pre[mask-a[i]-1];
                T[bit]+=pre[mask+mask-1-a[i]]-tt;
                T[bit]+=pre[mask*4-1-a[i]]-pre[mask*3-a[i]-1];
                if(a[i]+a[i]>=mask&&a[i]<mask) tmp++;
                if(a[i]+a[i]>=3*mask) tmp++;
            }
            else
            {
                T[bit]+=pre[mask+mask-1]-pre[mask-a[i]-1];
                if(a[i]+a[i]>=mask) tmp++;
            }
            //cout<<bit<<" "<<i<<" "<<T[bit]<<endl;
        }
        //cout<<T[bit]<<" "<<tmp<<endl;
        T[bit]-=tmp; T[bit]/=2;
        ans+=(T[bit]%2)*mask;
        for(int i=1;i<=n;i++) t[a[i]]--;
        if(!bit) break;
        for(int i=1;i<=n;i++) a[i]%=mask, t[a[i]]++; 
    }
    cout<<ans<<endl;
    return 0;
}