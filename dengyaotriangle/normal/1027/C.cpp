#include<bits/stdc++.h>

using namespace std;

const int maxn=1000006;

int n;
int cnt[maxn];
int a[maxn];
vector<int> v;

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cnt[a[i]]++;
        }
        v.clear();
        for(int i=1;i<=n;i++){
            if(cnt[a[i]]>=2){
                v.push_back(a[i]);
            }
            if(cnt[a[i]]>=4){
                v.push_back(a[i]);
            }
            cnt[a[i]]=0;
        }
        sort(v.begin(),v.end());
        int mi;
        long long cura=400000005,curb=1;
        for(int i=0;i<v.size()-1;i++){
            long long nva=(v[i+1]*v[i+1]+v[i]*v[i]);
            long long nvb=v[i+1]*v[i];
            if(cura*nvb>nva*curb){
                cura=nva;curb=nvb;mi=i;
            }
        }
        cout<<v[mi]<<' '<<v[mi]<<' '<<v[mi+1]<<' '<<v[mi+1]<<'\n';
    }
    return 0;
}//(a+b)^2/ab
//(a^2+b^2)/ab
//a^2/ab+b^2/ab
//a/b+b/a
//a=b=1/1+1/1=2

//ca/cb>na/nb
//canb>nacb