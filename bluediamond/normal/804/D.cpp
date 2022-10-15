#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back

const ll N = (ll)2e5 + 7;
ll n;
vector <ll> g2[N];
vector <ll> g[N];
bool gucci[N];
ll abi_talent_rege_pe_romania[N];
ll FVC;

void buildG(ll nod, ll rep) {
        FVC++;
        gucci[nod] = 1;
        abi_talent_rege_pe_romania[nod] = rep;
        for(auto &nou : g2[nod]) {
                if(gucci[nou])
                        continue;
                g[nod].pb(nou);
                buildG(nou, rep); } }

ll am_dat_clasa_cu_opt_clase[N];

void build_am_dat_clasa_cu_opt_clase(ll nod) {
        am_dat_clasa_cu_opt_clase[nod] = 1;
        for(auto &nou : g[nod]) {
                build_am_dat_clasa_cu_opt_clase(nou);
                am_dat_clasa_cu_opt_clase[nod] = max(am_dat_clasa_cu_opt_clase[nod], 1 + am_dat_clasa_cu_opt_clase[nou]); } }

ll up[N];

void build_up(ll nod) {
        /// 1 + up[nod]
        /// A, B
        ll A = 0;
        ll B = 0;
        vector <ll> keks;
        keks.pb(0);
        keks.pb(0);
        for(auto &nou : g[nod]) {
                keks.pb(1 + am_dat_clasa_cu_opt_clase[nou]); }
        sort(keks.rbegin(), keks.rend());
        A = keks[0];
        B = keks[1];
        for(auto &nou : g[nod]) {
                up[nou] = 1 + up[nod];
                ll C = A;
                if(1 + am_dat_clasa_cu_opt_clase[nou] == A) {
                        C = B; }
                up[nou] = max(up[nou], C);
                build_up(nou); } }

ll luv_dar[N];
vector <ll> nodes;
void calc(ll nod) {
        luv_dar[nod] = max(am_dat_clasa_cu_opt_clase[nod] - 1, up[nod]);
        nodes.pb(luv_dar[nod]);
        for(auto &nou : g[nod]) {
                calc(nou); } }

struct WakeMeUpWhenItisAllOver {
        ll sz;
        ll diam;
        ll sm;
        vector <ll> prefsum;
        vector <ll> polska; /// frequency
        /// polska has from [0, ..., diam]
};

map <pair <ll, ll>, ll> cnt;

void prll(ll a, ll b) {
        ld A = a;
        ld B = b;
        ld C = A / B;
        cout << fixed << setprecision(6) << C << "\n"; }

vector <WakeMeUpWhenItisAllOver> t;
ll get(ll a, ll l, ll r) {
        ll s = t[a].polska[r];
        if(l) {
                s -= t[a].polska[l - 1]; }
        return s; }

ll get_sum(ll a, ll l, ll r) {
        ll s = t[a].prefsum[r];
        if(l) {
                s -= t[a].prefsum[l - 1]; }
        return s; }
signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ll m, q;
        cin >> n >> m >> q;

        for(ll i = 1; i <= m; i++) {
                ll a, b;
                cin >> a >> b;
                g2[a].pb(b);
                g2[b].pb(a); }
        ll CUR = 0;
        for(ll i = 1; i <= n; i++) {
                if(abi_talent_rege_pe_romania[i] == 0) {
                        FVC = 0;
                        CUR++;
                        buildG(i, CUR);
                        build_am_dat_clasa_cu_opt_clase(i);
                        build_up(i);
                        up[i] = 1;
                        calc(i);
                        if(FVC == 1) {
                                luv_dar[i] = 0;
                                nodes[0] = 0; }
                        ll diam = 0;
                        ll sm = 0;
                        for(auto &it : nodes) {
                                diam = max(diam, it);
                                sm += it; }
                        vector <ll> prefsum(diam + 1, 0);
                        vector <ll> uga(diam + 1, 0);
                        for(auto &it : nodes) {
                                prefsum[it] += it;
                                uga[it]++; }
                        for(ll i = 1; i <= diam; i++) {
                                prefsum[i] += prefsum[i - 1];
                                uga[i] += uga[i - 1]; }
                        t.pb({FVC, diam, sm, prefsum, uga });
                        nodes.clear(); } }

        while(q--) {
                ll a, b;
                cin >> a >> b;
                a = abi_talent_rege_pe_romania[a] - 1;
                b = abi_talent_rege_pe_romania[b] - 1;
                if(a == b) {
                        cout << "-1\n";
                        continue; }
                if(t[a].diam > t[b].diam)
                        swap(a, b);
                if(t[a].diam == t[b].diam && a > b)
                        swap(a, b);
                ll tot = t[a].sz * t[b].sz;
                ll res = cnt[ {a, b }];
                if(res) {
                        prll(res, tot);
                        continue; }
                ll mi = max(t[a].diam, t[b].diam);
                res = t[a].sm * (ll)t[b].sz + t[b].sm * (ll)t[a].sz + t[a].sz * (ll)t[b].sz;
                for(ll i = 0; i <= t[a].diam; i++) {
                        ll dr = mi - i - 2;
                        if(dr > t[b].diam)
                                dr = t[b].diam;
                        if(dr < 0)
                                break;
                        ll delta = 0;
                        ll buga = get(b, 0, dr);
                        ll prefsum = get_sum(b, 0, dr);
                        delta += buga * mi;
                        delta -= prefsum + i * (ll)buga + buga;
                        delta *= (ll)get(a, i, i);
                        res += delta; }
                cnt[ {a, b }] = res;
                prll(res, tot); }


        return 0; }