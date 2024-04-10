line = [[] for i in range(4)]
for i in range(4):
    s = input()
    ss = []
    for j in range(4):
        ss += [s[j]]
    line[i] = ss
m = False
for i in range(4):
    for j in range(2):
        if line[i][j] == "x" and line[i][j+1] == "x" and line[i][j+2] == ".":
            m = True;
        if line[i][3-j] == "x" and line[i][2-j] == "x" and line[i][1-j] == ".":
            m = True;
        if line[i][j] == "x" and line[i][j+2] == "x" and line[i][j+1] == ".":
            m = True;
for i in range(4):
    for j in range(2):
        if line[j][i] == "x" and line[j+1][i] == "x" and line[j+2][i] == ".":
            m = True;
        if line[3-j][i] == "x" and line[2-j][i] == "x" and line[1-j][i] == ".":
            m = True;
        if line[j][i] == "x" and line[j+2][i] == "x" and line[j+1][i] == ".":
            m = True;
for i in range(2):
    for j in range(2):
        if line[i][j] == "x" and line[i+1][j+1] == "x" and line[i+2][j+2] == ".":
            m = True;
        if line[i][j] == "x" and line[i+2][j+2] == "x" and line[i+1][j+1] == ".":
            m = True;
        if line[i][j] == "." and line[i+2][j+2] == "x" and line[i+1][j+1] == "x":
            m = True;
for i in range(2, 4):
    for j in range(2):
        if line[i][j] == "x" and line[i-1][j+1] == "x" and line[i-2][j+2] == ".":
            m = True;
        if line[i][j] == "x" and line[i-2][j+2] == "x" and line[i-1][j+1] == ".":
            m = True;
        if line[i][j] == "." and line[i-2][j+2] == "x" and line[i-1][j+1] == "x":
            m = True;
if m:
    print("YES")
else:
    print("NO")