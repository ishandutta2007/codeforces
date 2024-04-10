#include <bits/stdc++.h>

using namespace std;

bool Viz[5];
int SG[5000000], Val[500000];
int k;

int get_SG(int i) {
    if(i <= 7) return SG[i];

    if(i % 2 == 1) return 0;
    if(k % 2 == 1 && get_SG(i / 2) == 1) return 2;
    return 1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, x;
    cin>>n>>k;

    int MAXX = 0;

    for(int i=1; i<=n; i++) {
        cin>>Val[i];
        MAXX = max(MAXX, Val[i]);
    }



    for(int i=1; i<=100; i++) {
        Viz[0] = Viz[1] = Viz[2] = Viz[3] = 0;

        Viz[SG[i-1]] = 1;
        if(i % 2 == 0) {
            if(k % 2 == 0)
                Viz[0] = 1;
            else
                Viz[SG[i/2]] = 1;
        }

        for(; Viz[SG[i]]; SG[i]++);

        //if(i <= 100) cout << SG[i] << " ";
    }

    int win = 0;
    for(int i=1; i<=n; i++)
        win ^= get_SG(Val[i]);

    for(int i=1; i<=100; i++)
        assert(SG[i] == get_SG(i));

    //cout << endl;
    if(win) cout << "Kevin";
    else cout << "Nicky";

    return 0;
}