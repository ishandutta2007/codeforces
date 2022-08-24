#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
vector <vector< int> > data;
vector<double> moneys;
vector<double> father;
vector<double> distances;
vector<vector< int > > comp;
vector<int> used;
vector<int> answer;
vector<int> old;
int bin(double money, double d){
    int left = -1;
    int right = old.size();
    while (right - left > 1){
        int m = (right + left) / 2;
        if (d - distances[old[m]] <= money){
            right = m;
        }
        else{
            left = m;
        }
    }
    return right;
}
int answer_dfs(int vertex){
    int balance = 0;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        balance += answer_dfs(to);
    }
    answer[vertex] = balance;
    for (int i=0;i<comp[vertex].size();i++){
        if (used[comp[vertex][i]] == 0){
            balance += 1;
        }
        else{
            balance -= 1;
        }
        used[comp[vertex][i]] ++;
    }
    return balance;
}
void dfs(int vertex){
    int money = moneys[vertex];
    int last = bin(money, distances[vertex]);
        if (last == old.size()){
            comp[vertex].push_back(vertex);
        }
        else{
            comp[old[last]].push_back(vertex);
        }
    comp[vertex].push_back(vertex);
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        old.push_back(vertex);
        dfs(to);
        old.pop_back();
    }
}
void prices_dfs(int vertex, double price){
    distances[vertex] = price;
    for (int i=0;i<data[vertex].size();i++){
        int to = data[vertex][i];
        prices_dfs(to, price + father[to]);
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    int n, pi;
    double wi, ai;
    cin >> n;
    for (int i=0;i<n;i++){
            used.push_back(0);
        vector<int> help;
        comp.push_back(help);
        data.push_back(help);
        answer.push_back(0);
        distances.push_back(0);
        father.push_back(0);
        cin >> ai;
        moneys.push_back(ai);
    }
    for (int i=1;i<n;i++){
        cin >> pi >> wi;
        data[pi - 1].push_back(i);
        father[i] = wi;
    }
    prices_dfs(0, 0);
    vector<int> help;
    dfs(0);
    answer_dfs(0);
    for (int i=0;i<answer.size() - 1;i++){
        cout << answer[i] << " ";
    }
    cout << answer[answer.size() - 1] << endl;
    return 0;
}