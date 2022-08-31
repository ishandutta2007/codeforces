string = input()
line = []
for i in range(7):
    line += [0]
for i in range(len(string)):
    if (string[i] == "B"):
        line[0] += 1
    if (string[i] == "u"):
        line[1] += 0.5  
    if (string[i] == "l"):
        line[2] += 1
    if (string[i] == "b"):
        line[3] += 1 
    if (string[i] == "a"):
        line[4] += 0.5  
    if (string[i] == "s"):
        line[5] += 1
    if (string[i] == "r"):
        line[6] += 1 
print(int(min(line)))