#include<bits/stdc++.h>
using namespace std;

int n,m,S,Q,z,L,R,k,l,r,x,ans,c[355][100005];
deque<int> dat[350];

void deal(int &x){
    x=(x+ans-1)%n+1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    S=int(sqrt(n));
    m=n/S+1;
    for(int i=0;i<n;i++){
        cin>>x;
        dat[i/S].push_back(x);
        c[i/S][x]++;
    }
    cin>>Q;
    while(Q--){
        cin>>z>>L>>R;
        deal(L);
        deal(R);
        if(L>R)swap(L,R);
        L--;
        l=L/S;
        r=R/S;
        if(z==2){
            cin>>k;
            deal(k);
            ans=0;
            if(l==r){
                for(int i=L%S,ed=R%S;i<ed;i++){
                    ans+=dat[l][i]==k;
                }
            }else{
                for(int i=l+1;i<r;i++)ans+=c[i][k];
                for(int i=L%S,ed=dat[l].size();i<ed;i++){
                    ans+=dat[l][i]==k;
                }
                for(int i=0,ed=R%S;i<ed;i++)ans+=dat[r][i]==k;
            }
            cout<<ans<<endl;
        }else{
            if(l==r){
                R=R%S-1;
                x=dat[r][R];
                dat[r].erase(dat[r].begin()+R);
                dat[l].insert(dat[l].begin()+L%S,x);
            }else{
                for(int i=l;i<r;){
                    x=dat[i].back();
                    dat[i].pop_back();
                    c[i][x]--;
                    i++;
                    dat[i].push_front(x);
                    c[i][x]++;
                }
                R%=S;
                x=dat[r][R];dat[r].erase(dat[r].begin()+R);c[r][x]--;
                dat[l].insert(dat[l].begin()+L%S,x);
                c[l][x]++;
            }
        }
    }

    return 0;
}