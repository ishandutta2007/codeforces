string = input()
start = False
finish = False
result = ""
alphabet = "abcdefghijklmnopqrstuvwxyz"
for i in range(len(string)):
    if not start:
        if string[i] != "a":
            result += alphabet[alphabet.find(string[i]) - 1]
            start = True
        else:
            result += "a"
    else:
        if not finish:
            if string[i] == "a":
                result += "a"
                finish = True
            else:
                result += alphabet[alphabet.find(string[i]) - 1]
        else:
            result += string[i]
if result == string:
    print(string[:-1] + "z")
else:
    print(result)