#include <bits/stdc++.h>
using namespace std;



struct matrix {
    long long  a[201][201];
};
matrix pr;
long long l;
int n;
string s;
string ss[205];
vector<string> v;
long long a[205];
long long q[205][30];
int nxt[205][30];
long long sum[205];
inline bool f(string a,string b){
    if ((int)a.size()<(int)b.size()) return false;
    for (int i=(int)a.size()-b.size(),j=0;i<a.size();++i,++j)
        if (a[i]!=b[j]) return false;
    return true;
}
inline matrix mult(matrix a,matrix b){
    matrix c;
    for (int i=0;i<v.size();++i){
        for (int j=0;j<v.size();++j)
            c.a[i][j]=-1e15;
    }
    for (int i=0;i<v.size();++i)
    for (int j=0;j<v.size();++j){
        for (int k=0;k<v.size();++k)
            c.a[i][k]=max(c.a[i][k],a.a[i][j]+b.a[j][k]);
    }
    return c;
}
matrix p(matrix a,long long y){
    if (y==1) return a;
    if (y&1) return mult(p(a,y-1),a);
    matrix c=p(a,y/2);
    return mult(c,c);
}
inline bool cmp(string a,string b){
    return (a.size()<b.size());
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>l;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i) {
        cin>>s;
        ss[i]=s;
        string last="";
        for (int j=0;j<s.size();++j) {
            last+=s[j];
            v.push_back(last);
        }
    }
    v.push_back("");
    sort(v.begin(),v.end(),cmp);
    for (int i=1;i<=n;++i)
        for (int j=0;j<v.size();++j)
            if (f(v[j],ss[i])) sum[j]+=a[i];
    for (int i=0;i<v.size();++i) {
        for (int j=0;j<26;++j) {
            string nw=v[i]+char(j+'a');
            for (int k=v.size()-1;k>=0;--k)
            if (f(nw,v[k])) {
                nxt[i][j]=k;
                q[i][j]=sum[k];
                break;
            }
        }
    }
    for (int i=0;i<v.size();++i)
        for (int j=0;j<v.size();++j)
            pr.a[i][j]=-1e15;
    for (int i=0;i<v.size();++i)
        for (int j=0;j<26;++j)
            pr.a[i][nxt[i][j]]=q[i][j];
    pr=p(pr,l);
    long long ans=0;
    for (int i=0;i<v.size();++i)
        ans=max(ans,pr.a[0][i]);
    cout<<ans;
}