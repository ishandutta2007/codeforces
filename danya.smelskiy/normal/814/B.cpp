#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int a[10001];
int b[10001];
bool used[100001];

int main(){
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    for (int i=1;i<=n;++i) {
        cin>>b[i];
        if (a[i]!=b[i]) v.push_back(i);
    }
    for (int i=1;i<=n;++i) {
        int k=0;
        for (int j=0;j<v.size();++j)
            if (i==v[j]) ++k;
        if (!k) used[a[i]]=true;
    }
    if (v.size()==1) {
        for (int i=1;i<=n;++i)
        if (used[i]==false && a[v[0]]!=i && b[v[0]]!=i) {
            a[v[0]]=i;
            break;
        }
    } else {
        int x=v[0];
        int y=v[1];
        int z=a[x];
        bool t=false;
        for (int i=1;i<=n;++i){
            a[x]=i;
            bool k=false;
            for (int j=1;j<=n;++j)
                used[j]=false;
            for (int j=1;j<=n;++j){
                if (used[a[j]])  k=true;
                else used[a[j]]=true;
            }
            if (k==true) continue;
            int rr=0;
            for (int j=1;j<=n;++j) {
                if (a[j]!=b[j]) ++rr;
            }
            if (rr>1) continue;
            t=true;
            break;
        }
        if (t==false) {
            a[x]=z;

        for (int i=1;i<=n;++i){
            a[y]=i;
            bool k=false;
            for (int j=1;j<=n;++j)
                used[j]=false;
            for (int j=1;j<=n;++j){
                if (used[a[j]])  k=true;
                else used[a[j]]=true;
            }
            if (k==true) continue;
            int rr=0;
            for (int j=1;j<=n;++j) {
                if (a[j]!=b[j]) ++rr;
            }
            if (rr>1) continue;
            t=true;
            break;
        }
        }
    }
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
}