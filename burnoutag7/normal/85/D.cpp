#include<bits/stdc++.h>
using namespace std;

int n,m,bs;
long long s[350][5];
vector<int> bk[350];
vector<int> v;

void add(const int &x){
    int c=(lower_bound(v.begin(),v.end(),x)-v.begin())/bs;
    bk[c].insert(lower_bound(bk[c].begin(),bk[c].end(),x),x);
    memset(s[c],0,sizeof(s[c]));
    for(int i=0;i<bk[c].size();i++)s[c][i%5]+=bk[c][i];
}

void del(const int &x){
    int c=(lower_bound(v.begin(),v.end(),x)-v.begin())/bs;
    bk[c].erase(lower_bound(bk[c].begin(),bk[c].end(),x));
    memset(s[c],0,sizeof(s[c]));
    for(int i=0;i<bk[c].size();i++)s[c][i%5]+=bk[c][i];
}

long long sum(){
    long long res=0;
    int tot=0;
    for(int i=0;i<=(m-1)/bs;i++){
        res+=s[i][(2-tot+5)%5];
        tot=(tot+bk[i].size())%5;
    }
    return res;
}

char op[100005];
int x[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    bs=sqrt(n);
    for(int i=0;i<n;i++){
        char buf[5];
        cin>>op[i]>>buf;
        if(op[i]=='a'){
            cin>>x[i];
            v.emplace_back(x[i]);
        }else
        if(op[i]=='d'){
            cin>>x[i];
            v.emplace_back(x[i]);
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    m=v.size();
    for(int i=0;i<n;i++){
        if(op[i]=='a'){
            add(x[i]);
        }else
        if(op[i]=='d'){
            del(x[i]);
        }else
        cout<<sum()<<endl;
    }

    return 0;
}