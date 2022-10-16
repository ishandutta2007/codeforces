//  228

#include<iostream>

using namespace std;

int a[103];

int main(){

ios_base::sync_with_stdio(0);
cin.tie(0), cout.tie(0);

int n;

cin >> n;

int g;

for(int i = 1 ; i <= n ; i++){
    cin >> g;

    a[g - 1] = i;
}

for(int i = 0 ; i < n ; i++){
    cout << a[i] << " ";
}

}