#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5+100;
int cnt[maxn];
vector<LL>app_nb;
void solve(int a,int b,int c){
    int ab=__gcd(a,b);
    int ac=__gcd(a,c);
    int bc=__gcd(b,c);
    int abc=__gcd(ab,c);

    app_nb.clear();
    app_nb.push_back(cnt[abc]);
    app_nb.push_back(cnt[ab]-cnt[abc]);
    app_nb.push_back(cnt[ac]-cnt[abc]);
    app_nb.push_back(cnt[bc]-cnt[abc]);
    app_nb.push_back(cnt[a]-cnt[ab]-cnt[ac]+cnt[abc]);
    app_nb.push_back(cnt[b]-cnt[ab]-cnt[bc]+cnt[abc]);
    app_nb.push_back(cnt[c]-cnt[ac]-cnt[bc]+cnt[abc]);
    LL ans = app_nb[0]+
		(app_nb[0]-1)*app_nb[0]+
		app_nb[4]*app_nb[5]*app_nb[6]+
		app_nb[4]*app_nb[5]*app_nb[2]+
		app_nb[4]*app_nb[5]*app_nb[3]+
		app_nb[4]*app_nb[5]*app_nb[0]+
		app_nb[4]*app_nb[1]*app_nb[6]+
		app_nb[4]*app_nb[1]*app_nb[2]+
		app_nb[4]*app_nb[1]*app_nb[3]+
		app_nb[4]*app_nb[1]*app_nb[0]+
		app_nb[4]*app_nb[3]*app_nb[6]+
		app_nb[4]*app_nb[3]*app_nb[2]+
		app_nb[4]*app_nb[3]*app_nb[0]+
		app_nb[4]*app_nb[0]*app_nb[6]+
		app_nb[4]*app_nb[0]*app_nb[2]+
		app_nb[1]*app_nb[5]*app_nb[6]+
		app_nb[1]*app_nb[5]*app_nb[2]+
		app_nb[1]*app_nb[5]*app_nb[3]+
		app_nb[1]*app_nb[5]*app_nb[0]+
		app_nb[1]*app_nb[3]*app_nb[6]+
		app_nb[1]*app_nb[3]*app_nb[2]+
		app_nb[1]*app_nb[3]*app_nb[0]+
		app_nb[1]*app_nb[0]*app_nb[6]+
		app_nb[1]*app_nb[0]*app_nb[2]+
		app_nb[2]*app_nb[5]*app_nb[6]+
		app_nb[2]*app_nb[5]*app_nb[3]+
		app_nb[2]*app_nb[5]*app_nb[0]+
		app_nb[2]*app_nb[1]*app_nb[6]+
		app_nb[2]*app_nb[3]*app_nb[6]+
		app_nb[2]*app_nb[3]*app_nb[0]+
		app_nb[2]*app_nb[0]*app_nb[6]+
		app_nb[0]*app_nb[5]*app_nb[6]+
		app_nb[0]*app_nb[5]*app_nb[3]+
		app_nb[0]*app_nb[3]*app_nb[6]+
		app_nb[0]*(app_nb[0]-1)*(app_nb[0]-2)/6+
		(app_nb[0]+app_nb[0]*(app_nb[0]-1)/2)*app_nb[4]+
		(app_nb[3]+app_nb[3]*(app_nb[3]-1)/2)*app_nb[4]+
		(app_nb[1]+app_nb[1]*(app_nb[1]-1)/2)*app_nb[6]+
		(app_nb[1]+app_nb[1]*(app_nb[1]-1)/2)*app_nb[2]+
		(app_nb[1]+app_nb[1]*(app_nb[1]-1)/2)*app_nb[3]+
		(app_nb[1]+app_nb[1]*(app_nb[1]-1)/2)*app_nb[0]+
		(app_nb[3]+app_nb[3]*(app_nb[3]-1)/2)*app_nb[1]+
		(app_nb[0]+app_nb[0]*(app_nb[0]-1)/2)*app_nb[1]+
		(app_nb[2]+app_nb[2]*(app_nb[2]-1)/2)*app_nb[5]+
		(app_nb[2]+app_nb[2]*(app_nb[2]-1)/2)*app_nb[1]+
		(app_nb[2]+app_nb[2]*(app_nb[2]-1)/2)*app_nb[3]+
		(app_nb[3]+app_nb[3]*(app_nb[3]-1)/2)*app_nb[2]+
		(app_nb[2]+app_nb[2]*(app_nb[2]-1)/2)*app_nb[0]+
		(app_nb[0]+app_nb[0]*(app_nb[0]-1)/2)*app_nb[2]+
		(app_nb[0]+app_nb[0]*(app_nb[0]-1)/2)*app_nb[5]+
		(app_nb[3]+app_nb[3]*(app_nb[3]-1)/2)*app_nb[0]+
		(app_nb[0]+app_nb[0]*(app_nb[0]-1)/2)*app_nb[3]+
		(app_nb[0]+app_nb[0]*(app_nb[0]-1)/2)*app_nb[6];
    printf("%lld\n",ans);
}
int main() {
    for(int X=1;X<=100000;++X) {

        for (int i = 1; i * i <= X; ++i) {
            if (X % i == 0) {
                cnt[X]++;
                if (i * i != X)
                    cnt[X]++;
            }
        }
    }
    int T;
    scanf("%d",&T);
    while(T--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (a==1&&b==1&&c==1){
            puts("1");
            continue;
        }
        solve(a,b,c);
    }
    return 0;
}