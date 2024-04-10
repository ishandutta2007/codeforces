#include<bits/stdc++.h>
using namespace std;

char s[100005];
int a[26][400005];
int q,n,n2;

void update(int pos,char val){
    int cur=pos+n2-1;
    while(cur>=1){
        a[s[pos]-'a'][cur]--;
        a[val-'a'][cur]++;
        cur>>=1;
    }
    s[pos]=val;
}

void init(int pos,char val){
    int cur=pos+n2-1;
    while(cur>=1){
        a[val-'a'][cur]++;
        cur>>=1;
    }
}

vector<int> query(int bk,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr){
        vector<int> v(26,0);
        for(int i=0;i<26;i++){
            v[i]=a[i][bk];
        }
        return v;
    }
    if(r<ql||qr<l){
        vector<int> v(26,0);
        return v;
    }
    vector<int> rl=query(bk<<1,l,(l+r)>>1,ql,qr);
    vector<int> rr=query((bk<<1)+1,((l+r)>>1)+1,r,ql,qr);
    vector<int> v(26,0);
    for(int i=0;i<26;i++){
        v[i]=rl[i]+rr[i];
    }
    return v;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s+1;
    n=strlen(s+1);
    n2=1;
    while(n2<n)n2<<=1;
    for(int i=1;i<=n;i++){
        init(i,s[i]);
    }
    cin>>q;
    while(q--){
        int typ;
        cin>>typ;
        if(typ==1){
            int x;
            char y;
            cin>>x>>y;
            update(x,y);
        }else{
            int x,y;
            cin>>x>>y;
            vector<int> v=query(1,1,n2,x,y);
            int ans=0;
            for(int i=0;i<v.size();i++){
                ans+=v[i]>0;
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}