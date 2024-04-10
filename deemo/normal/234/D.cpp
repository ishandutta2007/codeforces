#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<utility>
#include<string>
#include<fstream>

using namespace std;

struct Movie{
    string name;
    int tac;
    vector<int> actor;
};

vector<Movie>	  movies;
int n , k , t;
map<int , bool> fav;

void input(){
    ifstream fin("input.txt");
    fin >> n >> k;
    int temp;    

    for ( int i = 0 ; i < k ; i++ ){
	 fin >> temp;
	 fav[temp] = 1;
    }

    fin >> t;
    Movie temp_m;

    for ( int i = 0 ; i < t ; i++ ){
	 fin >> temp_m.name >> temp_m.tac;   
	 for ( int j = 0 ; j < temp_m.tac ; j++ ){
	     fin >> temp;
	     temp_m.actor.push_back(temp);
	 }
	 movies.push_back(temp_m);
	 temp_m.actor.clear();
    }
}

const int max_n = 100 + 30;
int maxi[max_n];//bishtarin arzeshi ke film i mituneh dashteh bashe
int mini[max_n];//kamtarin arzeshi ke film i mituneh dashteh bashe
int bishineh = -1 , bish = -1;//bish yani hadeaksar arzeshe ye film cheghadr mituneh bashe
int last_bish , bish_ind;
// bishineh yani hade aksar arzeshe film, hade aghal cheghadre

void get_Ans(){
    ofstream fout("output.txt");

    Movie m;
    int g , z , temp , temp2 , temp3;
    for ( int i = 0 ; i < t ; i++ ){
	 m = movies[i];
	 g = z = 0;
	 for ( int j = 0 ; j < m.actor.size() ; j++ ){
	     if ( fav[m.actor[j]] == 1 )	  g++;
	     if ( m.actor[j] == 0 )	 z++;
	 }
	 maxi[i] = g + (min(z , k - g));
	 if ( bish == -1 || bish < maxi[i] ){
	     last_bish = bish;
	     bish = maxi[i];
	     bish_ind = i;
	 }
	 else	  if ( last_bish < maxi[i] )  last_bish = maxi[i];

	 temp2 = m.actor.size() - g - z;//tedaade baazigar haaye gheire favorite dar in film
	 temp3 = (n - k) - temp2;//tedaade baazigar haaye gheire favorite ke tu in film nistan
	 temp = z - temp3;
	 if ( temp > 0 )	g += temp;
	 mini[i] = g;//hade aghal arzeshe in film barabar ast ba g
	 if ( bishineh == -1 || bishineh < g )   bishineh = g;  
    }

    for ( int i = 0 ; i < t ; i++ ){
	 if ( mini[i] == bish || ( bish_ind == i && last_bish <= mini[i] ) )  fout << 0 << endl;
	 else	  if ( maxi[i] >= bishineh )  fout << 2 << endl;
	 else	  fout << 1 << endl;
    }
}

int main(){
    input();
    get_Ans();
    return 0;

}