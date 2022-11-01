#include<bits/stdc++.h>
using namespace std;

int ask(int i,int j,int k){
    cout<<"? "<<i<<' '<<j<<' '<<k<<endl;
    int res;
    cin>>res;
    return res;
}

void answer(int i,int j){
    cout<<"! "<<i<<' '<<j<<endl;
}

void mian(){
    int n;
    cin>>n;
    int m1=1,m2=2;
    {
        vector<pair<int,int>> v;
        for(int i=1;i<=n;i++)if(i!=m1&&i!=m2){
            v.emplace_back(ask(m1,m2,i),i);
        }
        sort(v.begin(),v.end());
        if(v.front().first==v.back().first){
            if(ask(v.front().second,v.back().second,m1)<v.front().first){
                answer(m1,m2);
                return;
            }else{
                m1=v.front().second;
                m2=v.back().second;
            }
        }else{
            m1=v.back().second;
        }
    }
    {
        vector<pair<int,int>> v;
        for(int i=1;i<=n;i++)if(i!=m1&&i!=m2){
            v.emplace_back(ask(m1,m2,i),i);
        }
        sort(v.begin(),v.end());
        if(v.front().first==v.back().first){
            answer(m1,m2);
            return;
        }
        m2=v.back().second;
    }
    answer(m1,m2);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}