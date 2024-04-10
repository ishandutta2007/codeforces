#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    while(b){
        a=a%b;
        swap(b,a);
    }
    return a;
}

int n,a[500005],d1[500005],d2[500005];
vector<int> p;
bool pd[3505];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=2;i<=3500;i++)if(!pd[i]){
        p.emplace_back(i);
        for(int j=i+i;j<=3500;j+=i){
            pd[j]=1;
        }
    }

    cin>>n;
    memset(d1,-1,sizeof(d1));
    memset(d2,-1,sizeof(d2));
    register int sz,dvs[10];
    for(int i=0;i<n;i++){
        cin>>a[i];
        sz=0;
        int cur=a[i],a1=1,a2=1;
        for(int &j:p){
            if(j*j>cur)break;
            if(cur%j==0){
                dvs[sz++]=j;
                a2*=j;
                while(cur%j==0){
                    cur/=j;
                }
            }
        }
        if(cur>1)dvs[sz++]=cur,a2*=cur;
        for(int j=0;j+1<sz;j++){
            a1*=dvs[j];
            a2/=dvs[j];
            if(gcd(a1+a2,a[i])==1){
                d1[i]=a1;
                d2[i]=a2;
                break;
            }
        }
    }
    for(int i=0;i<n;i++)cout<<d1[i]<<' ';
    cout<<endl;
    for(int i=0;i<n;i++)cout<<d2[i]<<' ';
    cout<<endl;

    return 0;
}