#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,cen;
ll mx;
int a[500005],m[500005];
ll pre[500005],suf[500005];

void precalc(){
    stack<pair<int,int> > st;
    st.push(make_pair(0,0));
    for(int i=1;i<=n;i++){
        while(st.top().first>a[i])st.pop();
        pre[i]=pre[st.top().second]+(ll)a[i]*(i-st.top().second);
        st.push(make_pair(a[i],i));
    }
    while(!st.empty())st.pop();
    st.push(make_pair(0,n+1));
    for(int i=n;i>=1;i--){
        while(st.top().first>a[i])st.pop();
        suf[i]=suf[st.top().second]+(ll)a[i]*(st.top().second-i);
        st.push(make_pair(a[i],i));
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    precalc();
    for(int i=1;i<=n;i++){
        ll cur=pre[i]-a[i]+suf[i];
        if(cur>mx){
            mx=cur;
            cen=i;
        }
    }
    m[cen]=a[cen];
    int cur=a[cen];
    for(int j=cen-1;j>=1;j--){
        cur=min(cur,a[j]);
        m[j]=cur;
    }
    cur=a[cen];
    for(int j=cen+1;j<=n;j++){
        cur=min(cur,a[j]);
        m[j]=cur;
    }
    for(int i=1;i<=n;i++){
        cout<<m[i]<<' ';
    }
    cout<<endl;

    return 0;
}