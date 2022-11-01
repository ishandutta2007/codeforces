#include<bits/stdc++.h>
using namespace std;

bool pd[100005],kil[100005];
int n,cnt,tot;

int A(int x){
    assert(++cnt<=10000);
    cout<<"A "<<x<<endl;
    int res;
    cin>>res;
    return res;
}

int B(int x){
    assert(++cnt<=10000);
    cout<<"B "<<x<<endl;
    int res;
    cin>>res;
    return res;
}

void C(int x){
    assert(++cnt<=10000);
    cout<<"C "<<x<<endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=2;i<=100000;i++)if(!pd[i]){
        for(int j=i+i;j<=100000;j+=i)pd[j]=1;
    }
    cin>>n;
    tot=n;
    vector<int> v,d;
    for(int i=2;i<=n;i++)if(!pd[i]){
        static int tmp;
        tmp=B(i);
        if(tmp)v.emplace_back(i);
        tot-=tmp;
        if((int)v.size()%100==0){
            tmp=A(1);
            if(tmp!=tot){
                for(int &x:v)if(A(x))d.emplace_back(x);
            }
            tot=tmp;
            v.clear();
        }
    }
    if(A(1)!=tot){
        for(int x:v)if(A(x))d.emplace_back(x);
    }
    int ans=1;
    for(int &x:d){
        ans*=x;
        while((long long)ans*x<=n&&A(ans*x))ans*=x;
    }
    C(ans);

    return 0;
}