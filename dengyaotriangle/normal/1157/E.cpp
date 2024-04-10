#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
int a[maxn];
multiset<int> s;

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        s.insert(t);
    }
    for(int i=1;i<=n;i++){
        int d=n-a[i];
        multiset<int>::iterator it=s.lower_bound(d),it2=s.begin();
        if(it==s.end()) swap(it,it2);
        else if(((*it2)+a[i])%n<((*it)+a[i])%n) swap(it,it2);
        cout<<((*it)+a[i])%n<<' ';
        s.erase(it);
    }
    return 0;
}