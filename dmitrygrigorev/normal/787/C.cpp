#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <unordered_set>
#include <bitset>
using namespace std;
short ai, n, k;
vector<short> rick_moves, mortey_moves;
bool lose_rick[7000][7000], lose_mortey[7000][7000];
int cl[7000], cm[7000];
vector<short> win_rick, win_mortey;
short WIN = 2;
short WANT = 1;
short LOOP = 0;
short LOSE = -1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> k;
    for (int i=0;i<k;i++){
        cin >> ai;
        rick_moves.push_back(ai);
    }
    cin >> k;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            lose_rick[i][j] = false;
            lose_mortey[i][j] = false;
        }
    }
    for (int i=0;i<k;i++){
        cin >> ai;
        mortey_moves.push_back(ai);
    }
    for (int i=0;i<n;i++){
        cl[i] = 0;
        cm[i] = 0;
        win_rick.push_back(LOOP);
        win_mortey.push_back(LOOP);
    }
    for (int i=1;i<n;i++){
        for (int j=0;j<rick_moves.size();j++){
            int move = (i + rick_moves[j]) % n;
            if (move != 0){
                cl[i] ++;
                lose_rick[i][move] = true;
            }
        }
        for (int j=0;j<mortey_moves.size();j++){
            int move = (i + mortey_moves[j]) % n;
            if (move != 0){
                cm[i] ++;
                lose_mortey[i][move] = true;
            }
        }
    }
    for (int i=0;i<rick_moves.size();i++){
        int move = (-rick_moves[i] + n) % n;
        win_rick[move] = WANT;
    }
    for (int i=0;i<mortey_moves.size();i++){
        int move = (-mortey_moves[i] + n) % n;
        win_mortey[move] = WANT;
    }
    while (true){
        bool ch = false;
        for (int i=1;i<n;i++){
            if (win_mortey[i] == WANT){
                ch = true;
                win_mortey[i] = WIN;
                for (int j=0;j<rick_moves.size();j++){
                    int move = (i - rick_moves[j] + n) % n;
                    if (lose_rick[move][i]){
                    lose_rick[move][i] = false;
                    cl[move] --;
                    }
                }
            }
            if (win_rick[i] == WANT){
                ch = true;
                win_rick[i] = WIN;
                for (int j=0;j<mortey_moves.size();j++){
                    int move = (i - mortey_moves[j] + n) % n;
                    if (lose_mortey[move][i]){
                    lose_mortey[move][i] = false;
                    cm[move] --;
                    }
                }
            }
        }
        for (int i=1;i<n;i++){
            if (win_mortey[i] == 0 && cm[i] == 0){
                ch = true;
                win_mortey[i] = LOSE;
                for (int j=0;j<rick_moves.size();j++){
                    int move = (i - rick_moves[j] + n) % n;
                    if (win_rick[move] == LOOP){
                    win_rick[move] = WANT;
                    }
                }
            }
            if (win_rick[i] == 0 && cl[i] == 0){
                ch = true;
                win_rick[i] = LOSE;
                for (int j=0;j<mortey_moves.size();j++){
                    int move = (i - mortey_moves[j] + n) % n;
                    if (win_mortey[move] == LOOP){
                    win_mortey[move] = WANT;
                    }
                }
            }
        }
        if (!ch) break;
    }
    for (int i=1;i<n;i++){
        if (win_rick[i] == LOSE) cout << "Lose ";
        else if (win_rick[i] == LOOP) cout << "Loop ";
        else cout << "Win ";
    }
    cout << endl;
    for (int i=1;i<n;i++){
        if (win_mortey[i] == LOSE) cout << "Lose ";
        else if (win_mortey[i] == LOOP) cout << "Loop ";
        else cout << "Win ";
    }
    return 0;
}