#include <iostream>
using namespace std;
#define int long long

signed main() {
    int games, points, win, draw; cin >> games >> points >> win >> draw;
    for(int draws=0; draws<win; draws++) {
        if((points-draw*draws)%win != 0) continue;
        int wins = (points-draw*draws)/win;
        if(wins < 0) continue;
        if(games-draws-wins < 0) continue;
        cout << wins << ' ' << draws << ' ' << games-draws-wins << endl;
        return 0;
    }
    cout << -1 << endl;
}