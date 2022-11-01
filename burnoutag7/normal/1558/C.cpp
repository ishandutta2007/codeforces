#include<bits/stdc++.h>
using namespace std;

int n,a[2050];
vector<int> ans;

int fnd(int x){
    for(int i=1;;i++)if(a[i]==x)return i;
}

void rev(int x){
    ans.emplace_back(x);
    reverse(a+1,a+x+1);
}

bool deal(int m){
    if(m==1)return true;
    if(a[m-1]==m-1&&a[m]==m)return deal(m-2);
    int p1=fnd(m-1),pm=fnd(m);
    if(p1&1||pm&1^1)return false;
    rev(pm);
    pm=1;
    p1=fnd(m-1);
    rev(p1-1);
    rev(p1+1);
    rev(3);
    rev(m);
    return deal(m-2);
}

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans.clear();
    if(deal(n)){
        cout<<ans.size()<<'\n';
        for(int x:ans)cout<<x<<' ';
        cout<<'\n';
    }else cout<<"-1\n";
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