#include <iostream>
#include <cmath>
#include <math.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int n, ai;
vector<int> data;
bool dp[350][350][30][8];
bool used[350][350];
vector<vector<int> > sost;
long long answer;
void zero(int level, vector<int> sas, vector<vector<int> > &ss){
    int x = sas[0];
    int y = sas[1];
    for (int i=1;i<=data[level];i++){
        if (!used[x+i][y]){
            used[x+i][y] = true;
            answer ++;
        }
    }
    vector<int> help;
    if (!dp[x+data[level]][y][level][4]){
        help.push_back(x + data[level]);
        help.push_back(y);
        help.push_back(4);
        ss.push_back(help);
        dp[x+data[level]][y][level][4] = true;
    }
    help = {};
    if (!dp[x+data[level]][y][level][5]){
        help.push_back(x + data[level]);
        help.push_back(y);
        help.push_back(5);
        ss.push_back(help);
        dp[x+data[level]][y][level][5] = true;
    }
}
void one(int level, vector<int> sas, vector<vector<int> > &ss){
    int x = sas[0];
    int y = sas[1];
    for (int i=1;i<=data[level];i++){
        if (!used[x-i][y]){
            used[x-i][y] = true;
            answer ++;
        }
    }
    vector<int> help;
    if (!dp[x-data[level]][y][level][7]){
        help.push_back(x - data[level]);
        help.push_back(y);
        help.push_back(7);
        ss.push_back(help);
        dp[x-data[level]][y][level][7] = true;
    }
    help = {};
    if (!dp[x-data[level]][y][level][6]){
        help.push_back(x - data[level]);
        help.push_back(y);
        help.push_back(6);
        ss.push_back(help);
        dp[x-data[level]][y][level][6] = true;
    }
}
void two(int level, vector<int> sas, vector<vector<int> > &ss){
    int x = sas[0];
    int y = sas[1];
    for (int i=1;i<=data[level];i++){
        if (!used[x][y + i]){
            used[x][y + i] = true;
            answer ++;
        }
    }
    vector<int> help;
    if (!dp[x][y+data[level]][level][4]){
        help.push_back(x);
        help.push_back(y + data[level]);
        help.push_back(4);
        ss.push_back(help);
        dp[x][y+data[level]][level][4] = true;
    }
    help = {};
    if (!dp[x][y+data[level]][level][6]){
        help.push_back(x);
        help.push_back(y + data[level]);
        help.push_back(6);
        ss.push_back(help);
        dp[x][y+data[level]][level][6] = true;
    }
}
void three(int level, vector<int> sas, vector<vector<int> > &ss){
    int x = sas[0];
    int y = sas[1];
    for (int i=1;i<=data[level];i++){
        if (!used[x][y - i]){
            used[x][y - i] = true;
            answer ++;
        }
    }
    vector<int> help;
    if (!dp[x][y-data[level]][level][7]){
        help.push_back(x);
        help.push_back(y - data[level]);
        help.push_back(7);
        ss.push_back(help);
        dp[x][y-data[level]][level][7] = true;
    }
    help = {};
    if (!dp[x][y-data[level]][level][5]){
        help.push_back(x);
        help.push_back(y - data[level]);
        help.push_back(5);
        ss.push_back(help);
        dp[x][y-data[level]][level][5] = true;
    }
}
void four(int level, vector<int> sas, vector<vector<int> > &ss){
    int x = sas[0];
    int y = sas[1];
    for (int i=1;i<=data[level];i++){
        if (!used[x+i][y+i]){
            used[x+i][y+i] = true;
            answer ++;
        }
    }
    vector<int> help;
    if (!dp[x+data[level]][y + data[level]][level][2]){
        help.push_back(x + data[level]);
        help.push_back(y + data[level]);
        help.push_back(2);
        ss.push_back(help);
        dp[x+data[level]][y + data[level]][level][2] = true;
    }
    help = {};
    if (!dp[x+data[level]][y + data[level]][level][0]){
        help.push_back(x + data[level]);
        help.push_back(y + data[level]);
        help.push_back(0);
        ss.push_back(help);
        dp[x+data[level]][y + data[level]][level][0] = true;
    }
}
void five(int level, vector<int> sas, vector<vector<int> > &ss){
    int x = sas[0];
    int y = sas[1];
    for (int i=1;i<=data[level];i++){
        if (!used[x+i][y-i]){
            used[x+i][y-i] = true;
            answer ++;
        }
    }
    vector<int> help;
    if (!dp[x+data[level]][y - data[level]][level][3]){
        help.push_back(x + data[level]);
        help.push_back(y - data[level]);
        help.push_back(3);
        ss.push_back(help);
        dp[x+data[level]][y - data[level]][level][3] = true;
    }
    help = {};
    if (!dp[x+data[level]][y - data[level]][level][0]){
        help.push_back(x + data[level]);
        help.push_back(y - data[level]);
        help.push_back(0);
        ss.push_back(help);
        dp[x+data[level]][y - data[level]][level][0] = true;
    }
}
void six(int level, vector<int> sas, vector<vector<int> > &ss){
    int x = sas[0];
    int y = sas[1];
    for (int i=1;i<=data[level];i++){
        if (!used[x-i][y+i]){
            used[x-i][y+i] = true;
            answer ++;
        }
    }
    vector<int> help;
    if (!dp[x-data[level]][y + data[level]][level][2]){
        help.push_back(x - data[level]);
        help.push_back(y + data[level]);
        help.push_back(2);
        ss.push_back(help);
        dp[x-data[level]][y + data[level]][level][2] = true;
    }
    help = {};
    if (!dp[x-data[level]][y + data[level]][level][1]){
        help.push_back(x - data[level]);
        help.push_back(y + data[level]);
        help.push_back(1);
        ss.push_back(help);
        dp[x-data[level]][y + data[level]][level][1] = true;
    }
}
void seven(int level, vector<int> sas, vector<vector<int> > &ss){
    int x = sas[0];
    int y = sas[1];
    for (int i=1;i<=data[level];i++){
        if (!used[x-i][y-i]){
            used[x-i][y-i] = true;
            answer ++;
        }
    }
    vector<int> help;
    if (!dp[x-data[level]][y - data[level]][level][3]){
        help.push_back(x - data[level]);
        help.push_back(y - data[level]);
        help.push_back(3);
        ss.push_back(help);
        dp[x-data[level]][y - data[level]][level][3] = true;
    }
    help = {};
    if (!dp[x-data[level]][y - data[level]][level][1]){
        help.push_back(x - data[level]);
        help.push_back(y - data[level]);
        help.push_back(1);
        ss.push_back(help);
        dp[x-data[level]][y - data[level]][level][1] = true;
    }
}
int main()
{
    cin >> n;
    answer = 0;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    for (int x=0;x<350;x++){
        vector<bool> usedh;
        for (int y=0;y<350;y++){
            for (int level=0;level<n;level++){
                for (int nap=0;nap<8;nap++){
                    dp[x][y][level][nap] = false;
                    used[x][y] = false;
                }
            }
        }
    }
    vector<int> help;
    help.push_back(175);
    help.push_back(175);
    help.push_back(0);
    sost.push_back(help);
    for (int level = 0;level<n;level++){
    vector<vector<int > > ss;
    for (int i=0;i<sost.size();i++){
        if (sost[i][2] == 0){
            zero(level, sost[i], ss);
        }
        if (sost[i][2] == 1){
            one(level, sost[i], ss);
        }
        if (sost[i][2] == 2){
            two(level, sost[i], ss);
        }
        if (sost[i][2] == 3){
            three(level, sost[i], ss);
        }
        if (sost[i][2] == 4){
            four(level, sost[i], ss);
        }
        if (sost[i][2] == 5){
            five(level, sost[i], ss);
        }
        if (sost[i][2] == 6){
            six(level, sost[i], ss);
        }
        if (sost[i][2] == 7){
            seven(level, sost[i], ss);
        }
    }
    sost = ss;
    }
    cout << answer << endl;
    return 0;
}