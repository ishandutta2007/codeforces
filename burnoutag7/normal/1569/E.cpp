#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

int ival[]={1,2,3,5,9,17},rval[6];

template<bool original=false> vector<int> gen(int k,int s,bool irnk,bool champ){
    vector<int> res(1<<k);
    for(int i=1,rnk=k;i<1<<k;i<<=1,rnk--){
        for(int j=0;j<1<<k;j+=i<<1){
            int k1=j,k2=j+i;
            while(res[k1])k1++;
            while(res[k2])k2++;
            if constexpr(original)res[s&1?k1:k2]=ival[rnk+irnk];
            else res[s&1?k1:k2]=rval[rnk+irnk];
            s>>=1;
        }
    }
    for(int &x:res)if(!x)
        if constexpr(original)x=ival[x+(irnk&&!champ)];
        else x=rval[x+(irnk&&!champ)];
    return res;
}

map<int,int> deal(int k,int fid,bool irnk,bool champ){
    map<int,int> res;
    for(int s=0;s<1<<(1<<k)-1;s++){
        vector<int> rnk=gen(k,s,irnk,champ);
        int h=0;
        for(int i=0;i<1<<k;i++)h=(h+(ll)(i+fid)*rnk[i])%mod;
        res[h]=s;
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k,A,h;
    cin>>k>>A>>h;
    for(int i=0;i<=k;i++){
        rval[i]=A;
        for(int j=1;j<ival[i];j++)rval[i]=(ll)rval[i]*A%mod;
    }
    if(k==5){
        {
            map<int,int> lhf=deal(4,1,1,1),rhf=deal(4,17,1,0);
            for(auto &[ch,s]:lhf)if(rhf.count((h-ch+mod)%mod)){
                vector<int> ans=gen<1>(4,s,1,1);
                for(int x:ans)cout<<x<<' ';
                ans=gen<1>(4,rhf[(h-ch+mod)%mod],1,0);
                for(int x:ans)cout<<x<<' ';
                return 0;
            }
        }
        {
            map<int,int> lhf=deal(4,1,1,0),rhf=deal(4,17,1,1);
            for(auto &[ch,s]:lhf)if(rhf.count((h-ch+mod)%mod)){
                vector<int> ans=gen<1>(4,s,1,0);
                for(int x:ans)cout<<x<<' ';
                ans=gen<1>(4,rhf[(h-ch+mod)%mod],1,1);
                for(int x:ans)cout<<x<<' ';
                return 0;
            }
        }
        cout<<-1;
    }else{
        map<int,int> res=deal(k,1,0,1);
        if(res.count(h)){
            vector<int> ans=gen<1>(k,res[h],0,1);
            for(int x:ans)cout<<x<<' ';
        }else{
            cout<<-1;
        }
    }

    return 0;
}