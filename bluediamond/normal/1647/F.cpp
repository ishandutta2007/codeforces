#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home=1;


const int N=(int)5e5+7;
const int INF=(int)1e9+7;
int n;
int a[N];
int prefmin[N];
int sufmin[N];


int mx[N];
int mn[N];


/**

mn[i] => descrescator = i, crescator = mn[i]
mx[i] => descrescator = mx[i], crescator = i

**/

void relax_i(int i,int descrescator,int crescator){
        /// i = descresctor

        if(descrescator>a[i]){
                mn[i]=min(mn[i],crescator);
        }

        /// i = crescator

        if(crescator<a[i]){
                mx[i]=max(mx[i],descrescator);
        }
}

bool check(int lft,int rgh,int descrescator,int crescator){
        return crescator<a[rgh]&&descrescator>sufmin[rgh];
}

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


        while(cin>>n){
                for(int i=1;i<=n;i++){
                        cin>>a[i];
                }
                int sol=0;
                for(int Step=1;Step<=2;Step++){
                        int posmax=max_element(a+1,a+n+1)-a;
                        assert(1<=posmax&&posmax<=n);
                        assert(a[posmax]==*max_element(a+1,a+n+1));

                        {
                                prefmin[0]=-INF;
                                for(int i=1;i<=n;i++){
                                        prefmin[i]=INF;
                                        /// (a[i-1], prefmin[i-1])
                                        if(a[i-1]<a[i]) prefmin[i]=min(prefmin[i],prefmin[i-1]);
                                        if(prefmin[i-1]<a[i]) prefmin[i]=min(prefmin[i],a[i-1]);
                                }

                                sufmin[n+1]=-INF;
                                for(int i=n;i>=1;i--){
                                        sufmin[i]=INF;
                                        /// (a[i+1],sufmin[i+1)
                                        if(a[i+1]<a[i]) sufmin[i]=min(sufmin[i],sufmin[i+1]);
                                        if(sufmin[i+1]<a[i]) sufmin[i]=min(sufmin[i],a[i+1]);
                                }
                        }


                        int lft=posmax;

                        /**

                        from here I go on...

                        **/

                        /**

                        mn[i] => descrescator = i, crescator = mn[i]
                        mx[i] => descrescator = mx[i], crescator = i

                        **/


                        /**
                        descrescator : a[lft]
                        crescator    : prefmin[lft]

                        **/

                        mn[lft]=prefmin[lft];
                        mx[lft]=-INF; /// invalid


                        for(int i=lft+1;i<=n;i++){
                                mn[i]=INF;
                                mx[i]=-INF;

                                relax_i(i, a[i-1], mn[i-1]);
                                relax_i(i, mx[i-1], a[i-1]);
                        }

                        for(int rgh=lft+1;rgh<=n;rgh++){
                                if(prefmin[lft]<a[rgh]&&sufmin[rgh]<a[lft]){
                                ///        sol++;
                                        bool ok=0;
                                        ok|=check(lft, rgh, a[rgh-1], mn[rgh-1]);
                                        ok|=check(lft, rgh, mx[rgh-1], a[rgh-1]);
                                     /**   if(ok){
                                                sol++;
                                        }**/

                                        sol+=ok;
                                        ///cout<<": " <<lft<<" "<<rgh<<" : "<<ok<<"\n";
                                }
                        }

                  ///      return 0;
                        reverse(a+1,a+n+1);
                }
                cout<<sol<<"\n";
        }
}
/**
want =
3
4
0
0
1

**/