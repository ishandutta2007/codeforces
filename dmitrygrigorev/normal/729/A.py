a = int(input())
string = input()
first = []
last = []
sas = False
i = 1
while i < a:
    i += 1
    if not sas:
        if string[i-2:i+1] == "ogo":
            first += [i-2]
            sas = True
            i += 1
    else:
        if string[i-1:i+1] == "go":
            i += 1
        else:
            last += [i - 2]
            sas = False
if sas:
    last += [a - 1]
s = ""
counter = 0
n = 0
while counter < len(string):
    if counter not in first:
        s += string[counter]
        counter += 1
    else:
        s += "***"
        counter = last[n] + 1
        n += 1
print(s)