#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;
int n,v[N],s=0;
int st;
vector<int>x[7];
string a;

int iau(vector<int>a,vector<int>b) {
    if(a.size()==0) {
        return 2;
    }
    if(a.size()>b.size()) {
        return 1;
    }
    return 2;
}

vector<int>y[7];

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a;
    n=a.size();
    for(int i=1;i<=n;i++) {
        v[i]=a[i-1]-'0';
        x[v[i]%3].push_back(i);
        s+=v[i];
    }
    y[0]=x[0]; y[1]=x[1]; y[2]=x[2];
    st=1;while(v[st]==0 && st<n) {st++;}
    s%=3;
    if(s==0) {
        cout<<a<<"\n";
        return 0;
    }
    vector<int>print;
    if(s==1) {
        x[0]=y[0]; x[1]=y[1]; x[2]=y[2];
        if(x[1].size()) {    st=1;while(v[st]==0 && st<n) {st++;}
            int id=x[1].back();
            vector<int>ans;
            for(int j=st;j<=n;j++) {
                if(j==id) {
                    continue;
                }
                ans.push_back(v[j]);
            }
            st=0;
            while(st+1<ans.size() && ans[st]==0) {
                st++;
            }
            vector<int>lol;
            for(int i=st;i<ans.size();i++) {
                lol.push_back(ans[i]);
            }
            if(iau(print,lol)==2) {
                print=lol;
            }
        }
        x[0]=y[0]; x[1]=y[1]; x[2]=y[2];
        if(x[2].size()>=2) {    st=1;while(v[st]==0 && st<n) {st++;}
            int id1=x[2].back();;
            x[2].pop_back();
            int id2=x[2].back();
            vector<int>ans;
            for(int j=st;j<=n;j++) {
                if(j==id1 || j==id2) {
                    continue;
                }
                ans.push_back(v[j]);
            }
            st=0;
            while(st+1<ans.size() && ans[st]==0) {
                st++;
            }
            vector<int>lol;
            for(int i=st;i<ans.size();i++) {
                lol.push_back(ans[i]);
            }
            if(iau(print,lol)==2) {
                print=lol;
            }
        }
    }
    if(s==2) {
        x[0]=y[0]; x[1]=y[1]; x[2]=y[2];
        if(x[2].size()) {    st=1;while(v[st]==0 && st<n) {st++;}
            int id=x[2].back();
            vector<int>ans;
            for(int j=st;j<=n;j++) {
                if(j==id) {
                    continue;
                }
                ans.push_back(v[j]);
            }
            st=0;
            while(st+1<ans.size() && ans[st]==0) {
                st++;
            }
            vector<int>lol;
            for(int i=st;i<ans.size();i++) {
                lol.push_back(ans[i]);
            }
            if(iau(print,lol)==2) {
                print=lol;
            }
        }
        x[0]=y[0]; x[1]=y[1]; x[2]=y[2];
        if(x[1].size()>=2) {    st=1;while(v[st]==0 && st<n) {st++;}
            int id1=x[1].back();
            x[1].pop_back();
            int id2=x[1].back();
            vector<int>ans;
            for(int j=st;j<=n;j++) {
                if(j==id1 || j==id2) {
                    continue;
                }
                ans.push_back(v[j]);
            }
            st=0;
            while(st+1<ans.size() && ans[st]==0) {
                st++;
            }
            vector<int>lol;
            for(int i=st;i<ans.size();i++) {
                lol.push_back(ans[i]);
            }
            if(iau(print,lol)==2) {
                print=lol;
            }
        }
    }
    if(print.size()==0) {
        cout<<"-1\n";
        return 0;
    }
    for(auto itr:print) {
        cout<<itr;
    }
    cout<<"\n";
    return 0;
}