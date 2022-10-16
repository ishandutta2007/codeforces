#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1005;

struct st{
    int id;
    vector<int> v;
};

int t, n, k, ans[MM], maxv, maxv2, tot, LAST;
bool vis[MM];

int ask(vector<st> &a){
    assert(++tot <= 12);
    vector<int> out;
    for(auto &i: a)
        for(auto &j: i.v)
            out.push_back(j);
    cout<<"? "<<out.size();
    for(auto i: out)
        cout<<' '<<i;
    cout<<endl;
    int x;
    cin>>x;
    return x;
}

void go(vector<st> &a){
    vector<st> l, r;
    int m = a.size()/2;
    
    if(a.empty())
        return;
    if(a.size() == 1){
        //last one found, return
        LAST = a[0].id;
        return;
    }
    for(int i = 0; i < a.size(); i++){
//        print(i, m);
        if(i < m)
            l.emplace_back(a[i]);
        else
            r.emplace_back(a[i]);
    }
    int lv = ask(l);
    if(lv == maxv){
        swap(l, r);
    }
    //now it is on right
    for(auto &i: l){
        ans[i.id] = maxv;
    }
    go(r);
}

int main(){
    cin>>t;
    while(t--){
        tot = 0;
        memset(vis,0,sizeof vis);
        int cnt = 0;
        LAST = n+1;
        maxv = maxv2 = -1;
        cin>>n>>k;
        vector<st> a(k);
        for(int i = 0,m,b; i < k; i++){
            cin>>m;
            while(m--){
                cin>>b;
                a[i].v.emplace_back(b);
                vis[b] = 1;
                cnt++;
            }
            a[i].id = i;
        }
        if(cnt != n){
            vector<int> v;
            for(int i = 1; i <= n; i++){
                if(!vis[i]){
                    v.emplace_back(i);
                }
            }
            a.push_back({MM-2, v});
        }
        vector<st> b;
        if(k == 1){
            b.emplace_back(a.back());
            a.pop_back();
            int res = ask(b);
            cout<<"! "<<res<<endl;
            goto out;
        }
        
        maxv = ask(a);
        
        go(a);
        
        for(auto &i: a){
            if(i.id != LAST)
                b.emplace_back(i);
        }
        ans[LAST] = ask(b);
        
        
        cout<<"!";
        for(int i = 0; i < k; i++)
            cout<<' '<<ans[i];
        cout<<endl;
        
        out:;
        string s;
        cin>>s;
        if(s == "Incorrect")
            abort();
    }
    
    return 0;
}