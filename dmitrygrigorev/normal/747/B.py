n = int(input())
s = input()
line = [0, 0, 0, 0]
if n % 4 != 0:
    print("===")
else:    
    for i in range(len(s)):
        if s[i] == "A":
            line[0] += 1
        if s[i] == "C":
            line[1] += 1
        if s[i] == "T":
            line[2] += 1
        if s[i] == "G":
            line[3] += 1
    if max(line) > n // 4:
        print("===")
    else:
        ss = ""
        for i in range(len(s)):
            if (s[i] != "?"):
                ss += s[i]
            else:
                if (line[0] < n // 4):
                    ss += "A"
                    line[0] += 1
                else:
                    if (line[1] < n // 4):
                        ss += "C"  
                        line[1] += 1
                    else:    
                        if (line[2] < n // 4):
                            ss += "T"
                            line[2] += 1
                        elif (line[3] < n // 4):
                            ss += "G"   
                            line[3] += 1
        print(ss)