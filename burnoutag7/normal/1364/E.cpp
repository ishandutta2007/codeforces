#include<bits/stdc++.h>
using namespace std;

int n,z[11],bit;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int query(const int &x,const int &y){
    cout<<"? "<<x<<' '<<y<<endl;
    assert(x!=y);
    int tmp;
    cin>>tmp;
    return tmp;
}

inline int get(const int &pos){
    int res=(1<<bit)-1;
    for(int j=0;j<bit;j++){
        if(pos!=z[j])res&=query(pos,z[j]);
        else res&=((1<<bit)-1)^(1<<j);
    }
    return res;
}

inline void makez(){
    int cnt=0;
    while(cnt<bit){
        int x=rng()%n+1,y=rng()%n+1;
        if(x!=y){
            int cur=query(x,y);
            for(int i=0;i<bit;i++){
                if(!(cur>>i&1||z[i])){
                    z[i]=x;
                    cnt++;
                }
            }
        }
    }
}

inline void print(int *v){
    cout<<"! ";
    for(int i=1;i<=n;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    while(1<<bit<n)bit++;
    makez();
    int idx=1,val=get(idx);
    for(int i=2;i<=n;i++){
        if(val==query(idx,i)){
            idx=i;
            val=get(i);
        }
    }
    int *ans=new int[1<<11|5];
    for(int i=1;i<=n;i++){
        if(i!=idx)ans[i]=query(i,idx);
        else ans[i]=0;
    }
    print(ans);
    delete[] ans;

    return 0;
}