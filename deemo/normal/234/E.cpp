#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<utility>

using namespace std;

bool help(pair<string , int> a , pair<string , int> b){
    if ( a.second < b.second )  return true;
    return false;
}

int n , x , a , b , c;
int m;
vector< pair<string , int> >	vec;
vector< pair<string , int> >	basket[4];
vector< pair<string , int> >	  ans[20];

void put_in_baskets(){
    int ind = 0;
    for ( int i = 0 ; i < n ; i++ ){
	 if ( i != 0 && i % m == 0 )     ind += 1;
	 basket[ind].push_back(vec[i]);
    }
}

void input(){
    ifstream fin("input.txt");
    fin >> n;
    fin >> x >> a >> b >> c;
    m = n / 4;

    int temp;
    string temp_str;
    for ( int i = 0 ; i < n ; i++ ){
	 fin >> temp_str >> temp;
	 vec.push_back(make_pair(temp_str , temp));
    }
    sort(vec.begin() , vec.end() , help);
    reverse(vec.begin() , vec.end());
    put_in_baskets();
}

int ranm(){
    return x = (x * a + b) % c;
}

void del(int j , int g){
    vector< pair<string , int> >   temp;   
    for ( int i = 0 ; i < basket[j].size() ; i++ )
	 if ( i != g )   temp.push_back(basket[j][i]);
    basket[j].assign(temp.begin() , temp.end());
}

void get_Ans(){ 
    int k , j , t , g;
    for ( int i = 0 ; i < n ; i++ ){
	 k = ranm();
	 j = i % 4;
	 t = i / 4;
	 g = k % basket[j].size();
	 ans[t].push_back(basket[j][g]);
	 del(j , g);
    }
}

void show_Ans(){
    ofstream fout("output.txt");
    for ( int i = 0 ; i < m ; i++ ){
	 fout << "Group " << char(i + 65) << ":" << endl;
	 for ( int j = 0 ; j < ans[i].size() ; j++ )
	     fout << ans[i][j].first << endl;
    }	 
}

int main(){
    input();
    get_Ans();
    show_Ans();
    return 0;

}