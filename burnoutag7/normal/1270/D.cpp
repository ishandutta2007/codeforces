#include<bits/stdc++.h>
using namespace std;

int n,k,m;
vector<int> qs[505];
int val[505];

pair<int,int> ask(vector<int> &v){
    cout<<"? ";
    for(int i=0;i<v.size();i++)cout<<v[i]<<' ';
    cout<<endl;
    int pos,val;
    cin>>pos;if(pos==-1)exit(0);cin>>val;
    return make_pair(pos,val);
}

void solve(int cur){
    for(int i=1;i<=k+1;i++)if(i!=cur)qs[cur].push_back(i);
    pair<int,int> p=ask(qs[cur]);
    val[cur]=p.second;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int tms=1;tms<=k+1;tms++){
        solve(tms);
    }
    sort(val+1,val+1+k+1);m=1;
    for(int i=k;val[i]==val[i+1];i--,m++);
    cout<<"! "<<m<<endl;

    return 0;
}