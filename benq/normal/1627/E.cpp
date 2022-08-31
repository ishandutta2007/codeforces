#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
 
using namespace std;  // too many things to use, i give up
 
// https://codeforces.com/contest/1627/problem/E (sample omitted due to length)
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
 
    int test_num;
    cin >> test_num;
    for (int t = 0; t < test_num; t++) {
        int floor_num, room_num;
        int ladder_num;
 
        cin >> floor_num >> room_num >> ladder_num; // OK
        vector<long long> floors(floor_num);
        for (long long& f : floors) {
            cin >> f;
        }
 
        vector<vector<int>> floor_starts(floor_num);
        vector<vector<int>> floor_ends(floor_num);
        map<pair<int, int>, vector<pair<pair<int, int>, int>>> ladders;
        for (int l = 0; l < ladder_num; l++) {
            int s_floor, s_room;
            int e_floor, e_room;
            int health;
            cin >> s_floor >> s_room >> e_floor >> e_room >> health;
            assert(s_floor < e_floor);
 
            floor_starts[--s_floor].push_back(--s_room);
            floor_ends[--e_floor].push_back(--e_room);
            ladders[{s_floor, s_room}].push_back({{e_floor, e_room}, health});
        }
        floor_starts[floor_num - 1].push_back(room_num - 1);
        floor_ends[0].push_back(0);
 
        // cout << "ladders done" << endl;
        
        for (int f = 0; f < floor_num; f++) {
            sort(floor_starts[f].begin(), floor_starts[f].end());
            floor_starts[f].erase(unique(floor_starts[f].begin(), floor_starts[f].end()), end(floor_starts[f]));
            sort(floor_ends[f].begin(), floor_ends[f].end());
            floor_ends[f].erase(unique(floor_ends[f].begin(), floor_ends[f].end()), end(floor_ends[f]));
        }
 
        vector<map<int, long long>> min_cost(floor_num);
        min_cost[0][0] = 0;
        for (int f = 0; f < floor_num; f++) {
            if (min_cost[f].empty()) {
                continue;
            }
            vector<int> ends;
            for (int e : floor_ends[f]) {
                if (min_cost[f].count(e)) {
                    ends.push_back(e);
                }
            } // OK
            assert((int)ends.size() > 0);
 
            vector<long long> pref_min(ends.size());
            pref_min[0] = min_cost[f].at(ends.at(0));
            for (int e = 1; e < (int)ends.size(); e++) {
                pref_min[e] = std::min(
                    min_cost[f].at(ends[e]),
                    pref_min[e - 1] + floors[f] * (ends[e] - ends[e - 1])
                );
            }
 
            vector<long long> suff_min(ends.size());
            suff_min[(int)ends.size() - 1] = min_cost[f][ends[(int)ends.size() - 1]];
            for (int e = (int)ends.size() - 2; e >= 0; e--) {
                suff_min[e] = std::min(
                    min_cost[f].at(ends[e]),
                    suff_min[e + 1] + floors[f] * (ends[e + 1] - ends[e])
                );
            }
            
            int end_at = 0;
            for (int s : floor_starts[f]) {
                while (end_at < (int)ends.size() && ends.at(end_at) <= s) {
                    end_at++;
                }
                
                min_cost[f][s] = INT64_MAX;
                if (end_at > 0) {
                    min_cost[f][s] = 
                        pref_min[end_at - 1] + floors[f] * (s - ends[end_at - 1]);
                }
                if (end_at < (int)ends.size()) {
                    min_cost[f][s] = std::min(
                        min_cost[f][s],
                        suff_min[end_at] + floors[f] * (ends[end_at] - s)
                    );
                }
                
                if (f != floor_num || s != room_num) {
                    for (auto [next, hp] : ladders[{f, s}]) {
                        if (!min_cost[next.first].count(next.second)) {
                            min_cost[next.first][next.second] = INT64_MAX;
                        }
                        long long& dest = min_cost[next.first][next.second];
                        dest = std::min(dest, min_cost[f][s] - hp);
                    }
                }
            }
        }
 
        if (!min_cost[floor_num - 1].count(room_num - 1)) {
            cout << "NO ESCAPE" << '\n';
        } else {
            cout << min_cost[floor_num - 1][room_num - 1] << '\n';
        }
    }
}