#include<iostream>
#include<vector>

using namespace std;

int v;
int arr[13];
int mini = -1;
int ans[13];

void input(){
    cin >> v;
    for ( int i = 1 ; i < 10 ; i++ ){
	 cin >> arr[i];
	 if ( mini == -1 || arr[i] < mini )  mini = arr[i];
    }
}

int mindi;

int find(){
    mini = -1;  
    int ind;
    for ( int i = 1 ; i <= 9 ; i++ ){
	 if ( ( mini == -1 || mini <= ((v - arr[i]) / mindi) ) && v >= arr[i] ){
	     mini = (v - arr[i]) / mindi;
	     ind = i;
	 }
    }
    return ind;
}

void get_Ans(){
    int temp;
    mindi = mini;
    while( v >= mindi ){
	 temp = find();
	 ans[temp] += 1;
	 v -= arr[temp];
    }
}

void show_Ans(){
    for ( int i = 9 ; i > 0 ; i-- ){
	 for ( int j = 0 ; j < ans[i] ; j++ )
	     cout << i;
    }
    cout << endl;
}

int main(){
    input();
    if ( mini > v ){
	 cout << -1 << endl;
	 return 0;
    }
    get_Ans();
    show_Ans();
    return 0;
}