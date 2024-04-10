#include<bits/stdc++.h>
using namespace std;

int T,n,k;
char s[2005],t[2005];
vector<pair<int,int> > v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n>>k;
        cin>>s+1;
        memset(t,0,n+2);
        v.clear();
        for(int i=1;i<=n;i++){
            if(i<=(k-1)*2){
                t[i]=(i&1)?'(':')';
            }else{
                //original: \frac{n-(k-1) \times 2}{2}+(k-1) \times 2 \geq i
                t[i]=((n>>1)+k>i)?'(':')';
            }
        }
        //cerr<<t+1<<endl;
        for(int i=1;i<=n;i++){
            int j=i;
            while(s[j]!=t[i])j++;
            if(i==j)continue;
            v.push_back(make_pair(i,j));
            for(int k=i;k<j;++k,--j){
                swap(s[k],s[j]);
            }
        }
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i].first<<' '<<v[i].second<<endl;
        }
    }

    return 0;
}