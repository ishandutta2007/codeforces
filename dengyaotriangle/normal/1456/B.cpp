#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

struct node{
    node* c[2];
    vector<int> q[2];
    int pt[2];
};

node* nwnode(){
    node* nw=new node;
    nw->c[0]=nw->c[1]=NULL;
    nw->pt[0]=nw->pt[1]=-1;
    return nw;
}
int ls[2][32];


int main(){
    memset(ls,-1,sizeof(ls));
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<int> p=v;
    for(int i=1;i<n;i++)p[i]^=p[i-1];
    p.insert(p.begin(),0);
    node* rt=nwnode();
    int ans=INT_MAX;
    for(int i=0;i<=n;i++){
        node* u=rt;
        for(int j=31;j>=0;j--){
            bool dir=(p[i]>>j)&1;
            while(u->pt[!dir]+1<(int)u->q[!dir].size()&&u->q[!dir][u->pt[!dir]+1]<ls[dir][j])u->pt[!dir]++;
            if(u->pt[!dir]!=-1)ans=min(ans,i-u->q[!dir][u->pt[!dir]]-2);
            u->q[dir].push_back(i);
            ls[dir][j]=i;
            if(!u->c[dir])u->c[dir]=nwnode();
            u=u->c[dir];
        }
    }
    cout<<(ans==INT_MAX?-1:ans);
    return 0;
}