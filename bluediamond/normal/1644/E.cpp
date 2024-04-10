#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home=1;

struct T{
        int x;
        int y;
};

T operator + (T a,T b){
        return {a.x+b.x, a.y+b.y};
}

T operator - (T a,T b){
        return {a.x-b.x, a.y-b.y};
}

bool operator <= (T a,T b){
        return a.x<=b.x&&a.y<=b.y;
}

int times_fit(T limit,T current,T v){
        assert((v.x==1&&v.y==0)||(v.x==0&&v.y==1));
        if(v.x==0){
                swap(limit.x,limit.y);
                swap(current.x,current.y);
                swap(v.x,v.y);
        }
        assert(current<=limit);
        return limit.x-current.x;
}

const int N=(int)2e5+7;
int n;
T v[N];
T pref[N];

signed main() {
#ifdef ONLINE_JUDGE
          home = 0;
#endif


        if (home) {
                freopen("iron_man.txt", "r", stdin);
        }
        else {
                ios::sync_with_stdio(0); cin.tie(0);
        }

        int t;
        cin>>t;
        while(t--){
                ll dim;
                string s;
                cin>>dim>>s;
                n=(int)s.size();
                for(int i=1;i<=n;i++){
                        if(s[i-1]==s[0]){
                                v[i]={0, 1};
                        }else{
                                v[i]={1, 0};
                        }
                        pref[i]=pref[i-1]+v[i];
                }
                if(pref[n].x==0||pref[n].y==0){
                        cout<<dim<<"\n";
                        continue;
                }
                ll sol=(dim-pref[n].x)*(ll)(dim-pref[n].y);
                for(int i=1;i<=n;i++){
                        if(pref[i].x==0||pref[i].y==0){
                                sol++;
                        }else{
                                if(v[i].x==0){
                                        sol+=dim-pref[n].x;
                                }else{
                                        sol+=dim-pref[n].y;
                                }
                        }
                }
                cout<<sol<<"\n";
        }

}