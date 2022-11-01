#include<bits/stdc++.h>
using namespace std;

void z_algorithm(char *s,int *z,int n){
    int c=0;
    z[0]=0;
    for(int i=1;i<n;i++){
        if(i+z[i-c]<c+z[c]){
            z[i]=z[i-c];
        }else{
            int j=max(0,c+z[c]-i);
            while(i+j<n&&s[j]==s[i+j])j++;
            z[i]=j;
            c=i;
        }
    }
    z[0]=n;
}

int n,m,k;
char s[500005],t[500005],r[1000005];
int z[1000005];
int pre[500005];
int suf[500005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k>>s>>t;

    memcpy(r,t,m);
    memcpy(r+m,s,n);
    z_algorithm(r,z,n+m);
    for(int i=0;i<n;i++){
        if(z[i+m]>=m){
            cout<<"Yes"<<endl;
            if(i+k+k>n){
                cout<<n-k-k+1<<' '<<n-k+1<<endl;
            }else{
                cout<<i+1<<' '<<i+k+1<<endl;
            }
            return 0;
        }
    }
    {
        map<int,set<int>> mp;
        set<int> st;
        st.insert(1145141919);
        for(int i=0;i<n;i++)mp[min(z[i+m],m)].insert(i);
        for(int i=m;i>0;i--){
            for(const int &j:mp[i])st.insert(j);
            set<int>::iterator it=st.lower_bound(k-i);
            pre[i]=*it;
        }
    }
    reverse(r,r+m);
    reverse(r+m,r+m+n);
    z_algorithm(r,z,n+m);
    {
        map<int,set<int>> mp;
        set<int> st;
        st.insert(1145141919);
        for(int i=0;i<n;i++)mp[min(z[i+m],m)].insert(i);
        for(int i=m;i>0;i--){
            for(const int &j:mp[i])st.insert(j);
            set<int>::iterator it=st.lower_bound(k-i);
            suf[i]=*it;
        }
    }
    for(int i=1;i<m;i++){
        if(pre[i]==1145141919||suf[m-i]==1145141919)continue;
        if(i>k||m-i>k)continue;
        int lp=pre[i]+i-k+1,rp=n-suf[m-i]-m+i+1;
        if(lp+k>rp||rp+k-1>n)continue;
        cout<<"Yes"<<endl;
        cout<<lp<<' '<<rp<<endl;
        return 0;
    }
    cout<<"No"<<endl;

    return 0;
}