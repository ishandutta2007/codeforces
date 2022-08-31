n = int(input())
line = []
result = False
for i in range(n):
    string = input()
    if not result:
        if string[0] == "O" and string[1] == "O":
            string = "++" + string[2:]
            line += [string]
            result = True
        elif string[3] == "O" and string[4] == "O":
            string = string[:3]+ "++"
            line += [string]
            result = True  
        else:
            line += [string]
    else:
        line += [string]        
if not result:
    print("NO")
else:    
    print("YES")
    for i in range(n):
        print(line[i])