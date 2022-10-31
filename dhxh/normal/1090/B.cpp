#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <regex>
using namespace std;
string line;
regex re("\\\\cite\\{(\\w+)\\}");
regex emm("\\\\bibitem\\{(\\w+)\\}");
vector<string> seq, test, input;
int main()
{
   // freopen("in", "r", stdin);
    while (getline(cin, line)){
        if (line == "\\begin{thebibliography}{99}")
            break;
        for (sregex_iterator iter(line.begin(), line.end(), re), end; iter !=end; ++iter){
            seq.push_back((*iter)[1]);
        }
    }
    while (getline(cin, line)){
        if (line == "\\end{thebibliography}")
            break;
        input.push_back(line);
        sregex_iterator iter(line.begin(), line.end(), emm);
        test.push_back((*iter)[1]);
    }
    if (test == seq)
        puts("Correct");
    else{
        puts("Incorrect");
        puts("\\begin{thebibliography}{99}");
        for (auto i : seq){
            for (int j = 0; j < test.size(); ++j){
                if (i == test[j]){
                    puts(input[j].c_str());
                    break;
                }
            }
        }
        puts("\\end{thebibliography}");
    }
}