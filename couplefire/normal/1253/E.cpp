#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct Antenna
{
    int iniLeft, iniRight;
};
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int nbAntennas, totLen;
    cin >> nbAntennas >> totLen;
    vector<Antenna> ants(nbAntennas);
 
    for (int iAnt = 0; iAnt < nbAntennas; ++iAnt) {
        int center, iniScope;
        cin >> center >> iniScope;
        ants[iAnt].iniLeft = max(0, center - iniScope);
        ants[iAnt].iniRight = min(totLen, center + iniScope);
    }
 
    vector<int> minCost(totLen+1);
    minCost[totLen] = 0;
 
    for (int pos = totLen-1; pos >= 0; --pos) {
        minCost[pos] = (totLen - pos);
 
        for (int iAnt = 0; iAnt < nbAntennas; ++iAnt) {
            int left = ants[iAnt].iniLeft, right = ants[iAnt].iniRight;
 
            if (left <= pos+1 && pos+1 <= right) {
                minCost[pos] = minCost[pos+1];
                break;
            }
           
            if (pos < left) {
                int accessCost = (left - pos - 1);
                int nextPos = min(totLen, right + accessCost);
                minCost[pos] = min(minCost[pos], accessCost + minCost[nextPos]);
            }
        }
    }
 
    cout << minCost[0] << "\n";
 
    return 0;
}