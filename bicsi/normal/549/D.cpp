#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<unordered_map>

using namespace std;
typedef int var;


var A[500][500], B[500][500], n, m;

#define zeros(a) ((a)&(-a))

void add(var _i, var _j, var add) {
    for(var i = _i; i<=n; i+=zeros(i))
    for(var j = _j; j<=m; j+=zeros(j)) {
        B[i][j] += add;
    }
}

var get(var _i, var _j) {
    var sum = 0;
    for(var i = _i; i; i-=zeros(i))
    for(var j = _j; j; j-=zeros(j)) {
        sum += B[i][j];
    }
    return sum;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin>>n>>m;

    char ch;

    for(var i=1; i<=n; i++)
    for(var j=1; j<=m; j++) {
        cin>>ch;
        if(ch == 'W')
            A[i][j] = 1;
        else
            A[i][j] = -1;
    }


    var ops = 0;
    var lel = 0;

    for(var i=n; i>=1; i--)
    for(var j=m; j>=1; j--) {
        var val = get(i, j);

        if(val == A[i][j])
            continue;

        ops++;
        var dif = A[i][j] - val;

        add(1, 1, dif);
        add(1, j+1, -dif);
        add(i+1, 1, -dif);
        add(i+1, j+1, dif);
    }

    cout<<ops;




    return 0;
}