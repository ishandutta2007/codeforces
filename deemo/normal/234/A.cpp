#include<fstream>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<utility>
#include<string>

using namespace std;

int n;
string s;

void input(){
    ifstream fin("input.txt");
    fin >> n;
    fin >> s;
}

vector< pair<int , int> >	ans;

void get_Ans(){
    for ( int i = 1 ; i <= n / 2 ; i++ )
	 ans.push_back( make_pair(i , n / 2 + i) );
}

void show_Ans(){
    ofstream fout("output.txt");
    for ( int i = 0 ; i < ans.size() ; i++ ){
	 if ( s[ans[i].first - 1] == 'L' ){
	     fout << ans[i].first << " " << ans[i].second << endl;
	 }
	 else
	     fout << ans[i].second << " " << ans[i].first << endl;
    }
}

int main(){
    input();
    get_Ans();
    show_Ans();
    return 0;

}