#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
using namespace std;

map<string, int> score;
map<string, int> score2;
vector<pair<string, int>> scores;
//string wiener; int mscore;

int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        string name; int delta; cin >> name >> delta;
        if(score.count(name) == 0) score[name] = 0;
        score[name] += delta;
        scores.push_back(make_pair(name, delta));
    }
    string winner; int maxscore = -1000005, count = 0;
    for(auto name:score) {
        if(name.second == maxscore) count++;
        if(name.second > maxscore) {
            maxscore = name.second;
            count = 1;
            winner = name.first;
        }
    }
    if(count == 1) cout << winner << endl;
    else {
        string rwinner;
        for(auto entry:scores) {
            if(score2.count(entry.first) == 0) score2[entry.first] = 0;
            score2[entry.first] += entry.second;
            if(score[entry.first] == maxscore && score2[entry.first] >= maxscore) {
                rwinner = entry.first;
                //cout << entry.first << endl;
                break;
            }
        }
        cout << rwinner << endl;
    }
}