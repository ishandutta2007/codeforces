#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<utility>
#include<string>
#include<fstream>

using namespace std;

int n , z , counter;
const int max_n = 100 * 1000 + 20;
int arr[max_n];
int sec[max_n];
int d = -1;

void input(){
    ifstream fin("input.txt");
    fin >> n;
    int temp , ind = 1;

    for ( int i = 0 ; i < n ; i++ ){
	 fin >> temp;
	 if ( temp == 0 )	z++;
	 if ( temp < 0 )	counter++;
	 arr[ind] = counter;
	 sec[ind] = z;
	 ind++;
    }
}

int ans;

void get_Ans(){
    int mini = -1 , temp;
    for ( int i = 1 ; i <= n - 1 ; i++ ){
	 temp = i - arr[i];
	 temp += (counter - arr[i]) + (z - sec[i]);
	 if ( mini == -1 || mini > temp )	  mini = temp;
    }
    if ( mini != -1 )   ans = mini;
}

void show_Ans(){
    ofstream fout("output.txt");
    fout << ans << endl;
}

int main(){
    input();
    get_Ans();
    show_Ans();
    return 0;

}