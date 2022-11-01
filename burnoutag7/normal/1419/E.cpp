#include<bits/stdc++.h>
using namespace std;

inline int gcd(int a,int b){
    while(b){
        a=a%b;
        swap(a,b);
    }
    return a;
}

int n;
vector<int> pd;
set<int> u,nu;

void mian(){
    cin>>n;
    pd.clear();
    u.clear();
    {
        int c=n;
        for(int i=2;i*i<=c;i++){
            if(c%i==0){
                pd.emplace_back(i);
                while(c%i==0)c/=i;
            }
        }
        if(c>1){
            pd.emplace_back(c);
        }
    }
    {
        int c=n;
        for(int i=2;i*i<=c;i++){
            if(c%i==0){
                u.insert(i);
                u.insert(n/i);
            }
        }
        if(c>1){
            u.insert(c);
        }
    }
    if(pd.size()>1)u.erase(pd.front()*pd.back());
    for(int i=0;i<pd.size();i++){
        bool f=0;
        if(i+1<pd.size()){
            f=u.find(pd[i]*pd[i+1])!=u.end();
            u.erase(pd[i]*pd[i+1]);
        }
        nu.clear();
        for(const int &x:u){
            if(x%pd[i])nu.insert(x);
            else cout<<x<<' ';
        }
        swap(u,nu);
        if(f)cout<<pd[i]*pd[i+1]<<' ';
    }
    if(pd.size()>1)cout<<pd.front()*pd.back();
    cout<<'\n'<<(pd.size()==2&&pd.front()*pd.back()*2>n)<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}