//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int dp[10][1 << 9][1 << 9];
int n, m, cnt;
int ans[9][9];
const std::pair<int, int> T[4][5] = {
    {{-1, -1}, {-1, 0}, {-1, +1}, {0, 0}, {+1, 0}},
    {{-1, +1}, {0, -1}, {0, 0}, {0, +1}, {+1, +1}},
    {{-1, 0}, {0, 0}, {+1, -1}, {+1, 0}, {+1, +1}},
    {{-1, -1}, {0, -1}, {0, 0}, {0, +1}, {+1, -1}}};
struct node
{
    int x, y, z;
};
std::pair<std::pair<int, int>, std::vector<node>> from[10][1 << 9][1 << 9];
std::vector<node> operator+(const std::vector<node> &A, const node &B)
{
    std::vector<node> res = A;
    res.push_back(B);
    return res;
}
int G(int x, int y, int z)
{
    int res = 0;
    for (int i = 0; i != 5; ++i)
        if (T[z][i].first == x)
            res |= 1 << (y + T[z][i].second);
    return res;
}
template <class T>
void dfs(int line1, int line2, int line3, std::vector<node> x, T F, int l)
{
    F(line1, line2, line3, x);
    for (int i = 1; i + 1 < m; ++i)
        for (int j = 0; j != 4; ++j)
            if (!(line1 & G(-1, i, j)) && !(line2 & G(0, i, j)) && !(line3 & G(+1, i, j)))
                dfs(line1 | G(-1, i, j), line2 | G(0, i, j), line3 | G(+1, i, j), x + node{l, i, j}, F, l);
}
void work(int now, int x, int y)
{
    if (now == 1)
        return;
    work(now - 1, from[now][x][y].first.first, from[now][x][y].first.second);
    for (auto i : from[now][x][y].second)
    {
        ++cnt;
        for (int j = 0; j != 5; ++j)
            // std::cout << i.x + T[i.z][j].first << ' ' << i.y + T[i.z][j].second << std::endl,
            ans[i.x + T[i.z][j].first][i.y + T[i.z][j].second] = cnt;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::string S[10][10];
    S[1][1] = "0\n.\n",
    S[1][2] = "0\n..\n",
    S[1][3] = "0\n...\n",
    S[1][4] = "0\n....\n",
    S[1][5] = "0\n.....\n",
    S[1][6] = "0\n......\n",
    S[1][7] = "0\n.......\n",
    S[1][8] = "0\n........\n",
    S[1][9] = "0\n.........\n",
    S[2][1] = "0\n.\n.\n",
    S[2][2] = "0\n..\n..\n",
    S[2][3] = "0\n...\n...\n",
    S[2][4] = "0\n....\n....\n",
    S[2][5] = "0\n.....\n.....\n",
    S[2][6] = "0\n......\n......\n",
    S[2][7] = "0\n.......\n.......\n",
    S[2][8] = "0\n........\n........\n",
    S[2][9] = "0\n.........\n.........\n",
    S[3][1] = "0\n.\n.\n.\n",
    S[3][2] = "0\n..\n..\n..\n",
    S[3][3] = "1\nAAA\n.A.\n.A.\n",
    S[3][4] = "1\nAAA.\n.A..\n.A..\n",
    S[3][5] = "2\n.ABBB\n.A.B.\nAAAB.\n",
    S[3][6] = "2\n.ABBB.\n.A.B..\nAAAB..\n",
    S[3][7] = "3\nAAABCCC\n.A.B.C.\n.ABBBC.\n",
    S[3][8] = "3\nAAABCCC.\n.A.B.C..\n.ABBBC..\n",
    S[3][9] = "4\n.ABBBCDDD\n.A.B.C.D.\nAAABCCCD.\n",
    S[4][1] = "0\n.\n.\n.\n.\n",
    S[4][2] = "0\n..\n..\n..\n..\n",
    S[4][3] = "1\nA..\nAAA\nA..\n...\n",
    S[4][4] = "2\n.AAA\n.BA.\n.BA.\nBBB.\n",
    S[4][5] = "2\n.AAA.\n.BA..\n.BA..\nBBB..\n",
    S[4][6] = "3\nAAAB..\n.ACBBB\n.ACB..\n.CCC..\n",
    S[4][7] = "4\n.AAABBB\n.CA.DB.\n.CA.DB.\nCCCDDD.\n",
    S[4][8] = "4\n.AAABBB.\n.CA.DB..\n.CA.DB..\nCCCDDD..\n",
    S[4][9] = "5\nAAABBBC..\n.AD.BECCC\n.AD.BEC..\n.DDDEEE..\n",
    S[5][1] = "0\n.\n.\n.\n.\n.\n",
    S[5][2] = "0\n..\n..\n..\n..\n..\n",
    S[5][3] = "2\nA..\nAAA\nAB.\n.B.\nBBB\n",
    S[5][4] = "2\n...A\nBAAA\nBBBA\nB...\n....\n",
    S[5][5] = "4\nAAA.B\n.ABBB\nCA.DB\nCCCD.\nC.DDD\n",
    S[5][6] = "4\nA....B\nAAABBB\nACDDDB\n.C.D..\nCCCD..\n",
    S[5][7] = "5\nA.BBB.C\nAAABCCC\nAD.BE.C\n.D..E..\nDDDEEE.\n",
    S[5][8] = "6\nA..BBB.C\nAAADBCCC\nAE.DBF.C\n.EDDDF..\nEEE.FFF.\n",
    S[5][9] = "7\nA.BBB.CCC\nAAABDDDC.\nAE.BFDGC.\n.EFFFDG..\nEEE.FGGG.\n",
    S[6][1] = "0\n.\n.\n.\n.\n.\n.\n",
    S[6][2] = "0\n..\n..\n..\n..\n..\n..\n",
    S[6][3] = "2\nAAA\n.A.\nBA.\nBBB\nB..\n...\n",
    S[6][4] = "3\nA...\nAAAB\nABBB\nCCCB\n.C..\n.C..\n",
    S[6][5] = "4\nA.BBB\nAAAB.\nA.CB.\n.DCCC\n.DC..\nDDD..\n",
    S[6][6] = "5\nAAA..B\n.ACBBB\n.ACCCB\nD.CE..\nDDDE..\nD.EEE.\n",
    S[6][7] = "6\nAAAB...\n.ACBBBD\n.ACBDDD\nECCCF.D\nEEE.F..\nE..FFF.\n",
    S[6][8] = "7\n...AB...\nCAAABBBD\nCCCABDDD\nCEFFFG.D\n.E.F.G..\nEEEFGGG.\n",
    S[6][9] = "8\nA..BBB..C\nAAADBECCC\nADDDBEEEC\nFFFDGEH..\n.FGGG.H..\n.F..GHHH.\n",
    S[7][1] = "0\n.\n.\n.\n.\n.\n.\n.\n",
    S[7][2] = "0\n..\n..\n..\n..\n..\n..\n..\n",
    S[7][3] = "3\nAAA\n.A.\nBA.\nBBB\nBC.\n.C.\nCCC\n",
    S[7][4] = "4\n...A\nBAAA\nBBBA\nBCCC\n.DC.\n.DC.\nDDD.\n",
    S[7][5] = "5\nAAA.B\n.ABBB\nCA.DB\nCCCD.\nCEDDD\n.E...\nEEE..\n",
    S[7][6] = "6\nAAAB..\n.A.BBB\nCA.B.D\nCCCDDD\nCEFFFD\n.E.F..\nEEEF..\n",
    S[7][7] = "8\nAAABCCC\n.A.B.C.\nDABBBCE\nDDD.EEE\nDFGGGHE\n.F.G.H.\nFFFGHHH\n",
    S[7][8] = "9\nA.BBB..C\nAAABDCCC\nAE.BDDDC\n.EEEDFFF\nGEHHHIF.\nGGGH.IF.\nG..HIII.\n",
    S[7][9] = "10\nA.BBBCDDD\nAAAB.C.D.\nA.EBCCCDF\nEEEGGGFFF\nH.EIGJJJF\nHHHIG.J..\nH.III.J..\n",
    S[8][1] = "0\n.\n.\n.\n.\n.\n.\n.\n.\n",
    S[8][2] = "0\n..\n..\n..\n..\n..\n..\n..\n..\n",
    S[8][3] = "3\nA..\nAAA\nA.B\nBBB\nC.B\nCCC\nC..\n...\n",
    S[8][4] = "4\n...A\nBAAA\nBBBA\nB..C\nDCCC\nDDDC\nD...\n....\n",
    S[8][5] = "6\nA.BBB\nAAAB.\nAC.B.\n.CCCD\nECDDD\nEEEFD\nE..F.\n..FFF\n",
    S[8][6] = "7\nAAAB..\n.ACBBB\n.ACBD.\nECCCD.\nEEEDDD\nEFGGG.\n.F.G..\nFFFG..\n",
    S[8][7] = "9\n...ABBB\nCAAADB.\nCCCADB.\nCE.DDDF\n.EEEFFF\nGEHHHIF\nGGGH.I.\nG..HIII\n",
    S[8][8] = "10\nAAA.BCCC\n.ABBBDC.\nEA.FBDC.\nEEEFDDDG\nE.FFFGGG\nHHHIJJJG\n.H.I.J..\n.HIIIJ..\n",
    S[8][9] = "12\nA.BBB.CCC\nAAABDDDC.\nAE.BFD.CG\n.EFFFDGGG\nEEEHFIIIG\nJHHHK.IL.\nJJJHK.IL.\nJ..KKKLLL\n",
    S[9][1] = "0\n.\n.\n.\n.\n.\n.\n.\n.\n.\n",
    S[9][2] = "0\n..\n..\n..\n..\n..\n..\n..\n..\n..\n",
    S[9][3] = "4\nA..\nAAA\nA.B\nBBB\nC.B\nCCC\nCD.\n.D.\nDDD\n",
    S[9][4] = "5\nA...\nAAAB\nABBB\nC..B\nCCCD\nCDDD\nEEED\n.E..\n.E..\n",
    S[9][5] = "7\nA.BBB\nAAAB.\nAC.B.\n.CCCD\nECDDD\nEEE.D\nEFGGG\n.F.G.\nFFFG.\n",
    S[9][6] = "8\nA.BBB.\nAAABC.\nA.DBC.\nDDDCCC\nE.D..F\nEEEFFF\nEGHHHF\n.G.H..\nGGGH..\n",
    S[9][7] = "10\nAAABCCC\n.A.B.C.\nDABBBCE\nDDDFEEE\nD.GFFFE\nGGGFH..\nI.GJHHH\nIIIJH..\nI.JJJ..\n",
    S[9][8] = "12\nAAABCCC.\n.A.B.CD.\nEABBBCD.\nEEEFGDDD\nEFFFGGGH\nIIIFGHHH\n.IJKKKLH\n.IJ.K.L.\n.JJJKLLL\n",
    S[9][9] = "13\nAAAB..CCC\n.A.BDDDC.\nEABBBD.CF\nEEEGHDFFF\nEGGGHHHIF\nJJJGHIII.\n.JKLLLMI.\n.JK.L.M..\n.KKKLMMM.\n",
    std::cin >> n >> m;
    std::cout << S[n][m];
    return 0;
    if (n <= 2 || m <= 2)
    {
        std::cout << 0 << std::endl;
        for (int i = 0; i != n; ++i, std::cout << std::endl)
            for (int j = 0; j != m; ++j)
                std::cout << char(ans[i][j] ? 'A' - 1 + ans[i][j] : '.');
        return 0;
    }
    memset(dp, 0xf0, sizeof(dp));
    dp[1][0][0] = 0;
    for (int i = 1; i + 1 != n; ++i)
        for (int j = 0; j != 1 << m; ++j)
            for (int k = 0; k != 1 << m; ++k)
                dfs(
                    j, k, 0, {}, [&](const int &line1, const int &line2, const int &line3, const std::vector<node> &X)
                    {
                        if (dp[i + 1][line2][line3] < dp[i][j][k] + (int)X.size())
                            dp[i + 1][line2][line3] = dp[i][j][k] + X.size(), from[i + 1][line2][line3] = {{j, k}, X};
                    },
                    i);
    int maxx = 0, maxy = 0;
    for (int i = 0; i != 1 << m; ++i)
        for (int j = 0; j != 1 << m; ++j)
            if (dp[n - 1][i][j] > dp[n - 1][maxx][maxy])
                maxx = i, maxy = j;
    std::cout << dp[n - 1][maxx][maxy] << std::endl;
    work(n - 1, maxx, maxy);
    for (int i = 0; i != n; ++i, std::cout << std::endl)
        for (int j = 0; j != m; ++j)
            std::cout << char(ans[i][j] ? 'A' - 1 + ans[i][j] : '.');
    return 0;
}