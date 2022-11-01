#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
    int n, k;
    int t = 0;
    string w[2];
    cin >> n >> k >> w[0] >> w[1];
    
    queue<int> q;
    q.push(0);
    q.push(-1);
    w[0][0] = 'x';
    while( q.size() > 1 ){
        int z = q.front();
        q.pop();
        
        if( z == -1 ){
            ++t;
            q.push(-1);
            continue;
        }
        
        int p = z & 1;
        int h = z >> 1;

        if( h + k >= n ){
            puts("YES");return 0;
        }
        
        if( h - 1 > t && w[p][h-1] != 'X' ){
            q.push( (h-1)*2 + p);
            w[p][h-1] = 'X';
        }
        if( w[p][h+1] != 'X' ){
            q.push( (h+1)*2 + p);
            w[p][h+1] = 'X';
        }
        if( w[!p][h+k] != 'X') {
            q.push( (h+k)*2 + !p);
            w[!p][h+k] = 'X';
        }
    }
    puts("NO");
    return 0;
}