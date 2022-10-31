#include <bits/stdc++.h>
using namespace std;


vector<pair<int,int> > v;
string q[10];
map<string,int> kol;
long long ans;
vector<int> pr;
bool prime[100005];
int sz;
int n,m;

inline void add(int l){
    kol.clear();
    for (int i=0;i<pr.size();++i) {
        if (pr[i]>l) return;
        string s="";
        int nn=pr[i];
        while (nn) {
            s+=char('0'+nn%10);
            nn/=10;
        }
        reverse(s.begin(),s.end());
        string ss;
        while (s.size()<=5) {
        for (int j=0;j<s.size();++j) {
            ss=s;
            ss[j]='*';
            ++kol[ss];
        }
        ++kol[s];
        s="0"+s;
        }
    }
}


void recurs(int x,int y,long long z){
    if (!z) return;
    if (x==sz) {
        z*=kol[q[x]];
        ans+=z;
        return;
    }
    for (int i=0;i<=9;++i) {
        q[x][y-1]=char(i+'0');
        q[y][x-1]=char(i+'0');
        if (y<sz) recurs(x,y+1,z);
        else recurs(x+1,x+2,z*kol[q[x]]);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=2;i<=1e5;++i) if (prime[i]==false) {
        pr.push_back(i);
        for (int j=i+i;j<=1e5;j+=i)
            prime[j]=true;
    }
    add(99999);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>m;
        int last=1;
        sz=1;
        while (last<=m) {
            last*=10;
            ++sz;
        }
        --last; --sz;
        v.clear();
        string ss="";
        for (int j=2;j<=sz;++j) {
            for (int k=j+1;k<=sz;++k)
                v.push_back(make_pair(j,k));
        }
        while (m) {
            ss+=char('0'+m%10);
            m/=10;
        }
        reverse(ss.begin(),ss.end());
        q[1]=ss;
        for (int i=2;i<=sz;++i){
            q[i]="";
            for (int j=0;j<sz;++j)
                q[i]+="*";
            q[i][0]=ss[i-1];
        }
        ans=0;
        recurs(2,3,1);
        cout<<ans<<'\n';
    }
}