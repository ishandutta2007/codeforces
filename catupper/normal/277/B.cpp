#include<iostream>
#include<algorithm>

using namespace std;

int x, y;
int n, m;
int main(){
    cin >> n >> m;
    if(m == 3 && n > 4){
    cout << -1 << endl;
    return 0;
    }
    for(int i = 0;i < m;i++){
    cout << x <<' ' <<  y << endl;
    x++;
    y += i + 1;
    }
    x = 100000;
    y = 0;
    for(int i = 0;i < n - m;i++){
    cout << x << ' ' << y << endl;
    x--;
    y += i + 1;
    }
    return 0;
}